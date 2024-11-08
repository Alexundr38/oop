#include "Exception.h"

std::string InputSizeException::what() {
	std::string msg = "������: ������� ������������ ������. ����������, ���������� �����.";
	return msg;
}

std::string InputValueException::what() {
	std::string msg = "������: ������� ������������ ��������. ����������, ���������� �����.";
	return msg;
}

std::string InputCoordinatesException::what() {
	std::string msg = "������: ������� ������������ ����������. ����������, ���������� �����.";
	return msg;
}

std::string InputCoordAndOrientException::what() {
	std::string msg = "������: ������� ������������ ���������� � ����������. ����������, ���������� �����.";
	return msg;
}

std::string SetShipException::what() {
	std::string msg = "������� �� ����� ���� ���������� � ��������� �����.";
	return msg;
}

std::string UseAbilityException::what() {
	std::string msg = "� ������ ������� ��� ��� ������������, ������� ����� ���������.";
	return msg;
}

std::string InputSaveAnsException::what() {
	std::string msg = "������: ������� ������������ ������. ������� [y], ����� ��������� ����, ��� [n], ����� �� ���������.";
	return msg;
}