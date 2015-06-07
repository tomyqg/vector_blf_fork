#include <iostream>
#include <fstream>
#include <cstdio>

#include "Vector/BLF/File.h"

using namespace std;


void showCanMessage(Vector::BLF::CanMessage * canMessage)
{
	// Example output:
	// 00001617 | 0700 | 8 | 02 3e 80 55 55 55 55 55 | 2

	// convert the timestamp into milliseconds (1/10^3 of a second)
	unsigned long long actualTimestamp = ((Vector::BLF::ObjectHeader*)canMessage)->objectTimeStamp;
	Vector::BLF::ObjectHeader::ObjectFlags timestampUnits = ((Vector::BLF::ObjectHeader*)canMessage)->objectFlags;

	switch (timestampUnits)
	{
		case Vector::BLF::ObjectHeader::ObjectFlags::TimeOneNans:
			{
				// time unit is one nanosecond (1/10^9), so divide by 10^6
				actualTimestamp /= 1000000;
				break;
			}
		case Vector::BLF::ObjectHeader::ObjectFlags::TimeTenMics:
			{
				// time unit is ten microseconds (1/10^5), so divide by 10^2
				actualTimestamp /= 100;
				break;
			}
		default:
			{
				   // something is wrong
				   return;
			}
	}

	std::cout << std::dec << actualTimestamp
		<< " | "
		<< std::hex << (canMessage->id & 0x1fffffff) << std::dec
		<< " | "
		<< (unsigned short)canMessage->dlc
		<< " | ";

	

	for (int i = 0; (i < canMessage->dlc) && (i < 8); ++i) {
		std::cout << std::hex;
		if (canMessage->data[i] <= 0xf)
			std::cout << '0';
		std::cout << ((unsigned short)canMessage->data[i]);
		std::cout << " ";
	}
	std::cout << " | " << (unsigned short)canMessage->flags << std::endl;
}


int main(int argc, char *argv[])
{
	if ((argc != 2) && (argc != 3) ) {
		std::cout << "Parser <filename.blf> [channel to filter in]" << std::endl;
		return -1;
	}

	int channel = 0;
	bool shouldFilterByChannel = false;

	if (argc == 3)
	{
		channel = (int)strtol(argv[2], (char **)NULL, 10);
		shouldFilterByChannel = true;
	}

	// HACK: disable cerr
	std::cerr.setstate(std::ios::failbit);

	Vector::BLF::File file;
	file.open(argv[1]);

	while (!file.eof()) {
		Vector::BLF::ObjectHeaderBase * obj = file.read();

		if (obj == nullptr)
			continue;

		if (obj->objectType != Vector::BLF::ObjectType::CAN_MESSAGE)
			continue;

		if (shouldFilterByChannel)
		{
			Vector::BLF::CanMessage* message = reinterpret_cast<Vector::BLF::CanMessage *>(obj);
			if (message->channel != channel)
			{
				continue;
			}
		}

		showCanMessage(reinterpret_cast<Vector::BLF::CanMessage *>(obj));

		/* delete object */
		delete obj;
	}

	file.close();

	return 0;
}
