#include "Exception.h"

std::string InputSizeException::what() {
	std::string msg = "Ошибка: введены некорректные данные. Пожалуйста, попробуйте снова.";
	return msg;
}

std::string InputValueException::what() {
	std::string msg = "Ошибка: введено некорректное значение. Пожалуйста, попробуйте снова.";
	return msg;
}

std::string InputCoordinatesException::what() {
	std::string msg = "Ошибка: введены некорректные координаты. Пожалуйста, попробуйте снова.";
	return msg;
}

std::string InputCoordAndOrientException::what() {
	std::string msg = "Ошибка: введены некорректные координаты и ориентация. Пожалуйста, попробуйте снова.";
	return msg;
}

std::string SetShipException::what() {
	std::string msg = "Корабль не может быть расположен в указанном месте.";
	return msg;
}

std::string UseAbilityException::what() {
	std::string msg = "В данный моменту вас нет способностей, которые можно применить.";
	return msg;
}

std::string InputSaveAnsException::what() {
	std::string msg = "Ошибка: введены некорректные данные. Введите [y], чтобы сохранить игру, или [n], чтобы не сохранять.";
	return msg;
}