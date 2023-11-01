/*
ADV-aceSplint - by Belbo
*/

params ["_selectionNumber"];

private _return = ["","",_selection];
if (_selectionNumber isEqualTo 2) then {
	_return = ["hithands","hitleftarm","hand_l",localize "STR_ADV_ACESPLINT_ARM"];
} else if (_selectionNumber isEqualTo 3) then {
	_return = ["hithands","hitrightarm","hand_r",localize "STR_ADV_ACESPLINT_ARM"];
} else if (_selectionNumber isEqualTo 4) then {
	_return = ["hitlegs","hitleftleg","leg_l",localize "STR_ADV_ACESPLINT_LEG"];
} else if (_selectionNumber isEqualTo 5) then {
	_return = ["hitlegs","hitrightleg","leg_r",localize "STR_ADV_ACESPLINT_LEG"];
};

_return