#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

class InputSizeException{
public:
	InputSizeException() = default;
	std::string what();
};

class InputValueException {
public:
	InputValueException() = default;
	std::string what();	
};

class InputCoordinatesException {
public:
	InputCoordinatesException() = default;
	std::string what();
};

class InputCoordAndOrientException {
public:
	InputCoordAndOrientException() = default;
	std::string what();
};

class SetShipException {
public:
	SetShipException() = default;
	std::string what();
};

class UseAbilityException {
public:
	UseAbilityException() = default;
	std::string what();
};

class RandomSetShipException {
public:
	RandomSetShipException() = default;
};

class InputLoadException {
public:
	InputLoadException() = default;
	std::string what();
};

class InputSaveAnsException {
public:
	InputSaveAnsException() = default;
	std::string what();
};

class OpenFileException {
public:
	OpenFileException() = default;
	std::string what();
};
#endif