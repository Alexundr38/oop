#include "Exception.h"

std::string InputSizeException::what() {
	std::string msg = "Îøèáêà: ââåäåíû íåêîððåêòíûå äàííûå. Ïîæàëóéñòà, ïîïðîáóéòå ñíîâà.";
	return msg;
}

std::string InputValueException::what() {
	std::string msg = "Îøèáêà: ââåäåíî íåêîððåêòíîå çíà÷åíèå. Ïîæàëóéñòà, ïîïðîáóéòå ñíîâà.";
	return msg;
}

std::string InputCoordinatesException::what() {
	std::string msg = "Îøèáêà: ââåäåíû íåêîððåêòíûå êîîðäèíàòû. Ïîæàëóéñòà, ïîïðîáóéòå ñíîâà.";
	return msg;
}

std::string InputCoordAndOrientException::what() {
	std::string msg = "Îøèáêà: ââåäåíû íåêîððåêòíûå êîîðäèíàòû è îðèåíòàöèÿ. Ïîæàëóéñòà, ïîïðîáóéòå ñíîâà.";
	return msg;
}

std::string SetShipException::what() {
	std::string msg = "Êîðàáëü íå ìîæåò áûòü ðàñïîëîæåí â óêàçàííîì ìåñòå.";
	return msg;
}

std::string UseAbilityException::what() {
	std::string msg = "Â äàííûé ìîìåíòó âàñ íåò ñïîñîáíîñòåé, êîòîðûå ìîæíî ïðèìåíèòü.";
	return msg;
}

std::string OpenFileException::what() {
	std::string msg = "Íå íàéäåíî ñîõðàíåíèé";
	return msg;
}

std::string UnknownCommandException::what() {
	std::string msg = "Íåèçâåñòíàÿ êîìàíäà";
	return msg;
}

std::string AttackCommandException::what() {
	std::string msg = "Â äàííûé ìîìåíò íåâîçìîæíî àòàêîâàòü";
	return msg;
}

std::string UseAbilityCommandException::what() {
	std::string msg = "Â äàííûé íåâîçìîæíî èñïîëüçîâàòü ñïîñîáíîñòü";
	return msg;
}

std::string SaveCommandException::what() {
	std::string msg = "Â äàííûé ìîìåíò íåâîçìîæíî ñîõðàíèòü èãðó";
	return msg;
}