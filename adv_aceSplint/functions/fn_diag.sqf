/*
ADV-aceSplint - by Belbo
*/

params [
	"_target"
	,"_log"
];

//exit if diagnostics is not activated:
if !(missionNamespace getVariable ["adv_aceSplint_diag",false]) exitWith {false};

//log event local to the caller:
private _str = format ["adv_aceSplint - %1",_log];
if (local _target) then {
	["adv_aceSplint_evh_log", [_str]] call CBA_fnc_localEvent;
} else {
	["adv_aceSplint_evh_log", [_str]] call CBA_fnc_localEvent;
	["adv_aceSplint_evh_log", [_str], _target] call CBA_fnc_targetEvent;
};

true