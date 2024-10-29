#include "Player.h"

void Player::setField(int height, int width) {
	this->field = new PlayingField{ height, width };
}

void Player::setShipManager() {}

void Player::setAbilityManager() {}

PlayingField* Player::getField() {
	return this->field;
}

ShipManager* Player::getShipManager() {
	return this->ship_manager;
}

AbilityManager* Player::getAbilityManager() {
	return this->ability_manager;
}