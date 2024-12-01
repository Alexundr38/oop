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
	std::string msg = "������: ������� ������������ ������. ������� [s], ����� ��������� ����, [l], ����� ��������� ����, [g], ����� ������ ����� ����, [q], ����� ����� �� ����, [n], ����� ����������";
	return msg;
}

std::string InputLoadException::what() {
	std::string msg = "������: ������� ������������ ������. ������� [y], ����� ��������� ����, [n], � ��������� ������";
	return msg;
}

std::string OpenFileException::what() {
	std::string msg = "�� ������� ����������";
	return msg;
}

std::string UnknownCommandException::what() {
	std::string msg = "����������� �������";
	return msg;
}

std::string AttackCommandException::what() {
	std::string msg = "� ������ ������ ���������� ���������";
	return msg;
}

std::string UseAbilityCommandException::what() {
	std::string msg = "� ������ ���������� ������������ �����������";
	return msg;
}

std::string SaveCommandException::what() {
	std::string msg = "� ������ ������ ���������� ��������� ����";
	return msg;
}