/*
ADV-aceSplint - by Belbo
*/

params ["_target","_selection"];

private _hhpaab = missionNamespace getVariable ["ace_medical_healHitPointAfterAdvBandage",false];
private _enable = missionNamespace getVariable ["adv_aceSplint_enable",true];

if ( _hhpaab || !_enable ) exitWith { false };

private _hitPoint = _selection;
if ((toLower _selection) in ["hand_l","hand_r"]) then {
	_hitPoint = "HitHands";
} else if ((toLower _selection) in ["leg_l","leg_r"]) then {
	_hitPoint = "HitLegs";
};

if ((_target getHitPointDamage _hitPoint) < 0.5) exitWith { false };

//if !([_target] call ace_medical_fnc_isInStableCondition) exitWith { false };

true