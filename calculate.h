#pragma once

struct PlayerInfo {
	int getPlayerDPI();
	double getPlayerSens();
};

struct UserPrompt {
	// prompt with the menu after each conversion iteration
	void userChoices(UI& ui, UserPrompt& up, PlayerInfo& pi);
};

struct ConvertToCm360 {
	double convert(int dpi, double sens);
	void output(UI& ui, UserPrompt& up, PlayerInfo& pi, ConvertToCm360& cm);
};

struct ConvertToSensitivity {

};