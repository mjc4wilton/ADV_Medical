﻿class CfgPatches
{
    class adv_aceCPR
    {
        units[] = {
			"adv_aceCPR_AEDItem"
		};
        weapons[] = {
			"adv_aceCPR_AED"
		};
        requiredVersion = 1.88;
        requiredAddons[] = {
			"ace_medical"
			,"cba_settings"
		};
		version = "2.1.4";
		versionStr = "2.1.4";
		author = "[SeL] Belbo // Adrian";
		authorUrl = "http://spezialeinheit-luchs.de/";
    };
};

#define MACRO_ADDITEM(ITEM,COUNT) class _xx_##ITEM { \
    name = #ITEM; \
    count = COUNT; \
}

class CfgFunctions {
	class adv_aceCPR {
		tag = "adv_aceCPR";
		class init {
			file = "adv_aceCPR\functions";
			class addTime {};
			class AED_action {};
			class AED_condition {};
			class AED_local {};
			class AED_sound {};
			class AED_cancelled {};
			class AED_progress {};
			class AED_station {};
			class AED_station_condition {};
			class CPR_action {};
			class CPR_local {};
			class createAEDstations {};
			class diag {};
			class getBloodLoss {};
			class getList {};
			class init { postInit = 1; };
			class isResurrectable {};
			class probability {};
			class registerSettings {};
			class useAEDStation {};

			class giveHeartRate {};
			class getMedications {};
			class inReviveState {};
		};
	};
};

class Extended_PreInit_EventHandlers {
	class adv_aceCPR_preInit {
		init = "call adv_aceCPR_fnc_registerSettings";
	};
};

class Extended_PostInit_EventHandlers {
    class adv_aceCPR_postInit {
        init = "nul = [] spawn adv_aceCPR_fnc_createAEDstations";
    };
};

class cfgWeapons {
	class ACE_ItemCore;
	class CBA_MiscItem_ItemInfo;
	
    class adv_aceCPR_AED: ACE_ItemCore {
        scope = 2;
        displayName = "$STR_ADV_ACECPR_AED_DISPLAYNAME";
        picture = "\adv_aceCPR\ui\defib.paa";
		model = "\A3\Structures_F_EPA\Items\Medical\Defibrillator_F.p3d";
        descriptionShort = "$STR_ADV_ACECPR_AED_DESCRIPTION";
        descriptionUse = "$STR_ADV_ACECPR_AED_DESCRIPTION";
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 30;
        };
	};	
    class adv_aceCPR_AED_used: ACE_ItemCore {
        scope = 1;
        displayName = "$STR_ADV_ACECPR_AED_USED_DISPLAYNAME";
        picture = "\adv_aceCPR\ui\defib.paa";
		model = "\A3\Structures_F_EPA\Items\Medical\Defibrillator_F.p3d";
        descriptionShort = "$STR_ADV_ACECPR_AED_DESCRIPTION";
        descriptionUse = "$STR_ADV_ACECPR_AED_DESCRIPTION";
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 30;
        };
	};
};

class cfgVehicles {
	class Item_Base_F;
	
	class adv_aceCPR_AEDItem: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = "$STR_ADV_ACECPR_AED_DISPLAYNAME";
        author = "[SeL] Belbo";
        vehicleClass = "Items";
		model = "\A3\Structures_F_EPA\Items\Medical\Defibrillator_F.p3d";
        class TransportItems {
            MACRO_ADDITEM(adv_aceCPR_AED,1);
        };
	};

	class Items_base_F;
	class Land_Defibrillator_F: Items_base_F {
		ace_dragging_canCarry = 1;
		ace_dragging_carryPosition[] = {0,1,1};
		ace_dragging_carryDirection = 270;
        ace_cargo_size = 1;
		ace_cargo_canLoad = 1;
	};
	
	class ACE_medicalSupplyCrate;
	class ACE_medicalSupplyCrate_advanced: ACE_medicalSupplyCrate {
		class TransportItems {
			MACRO_ADDITEM(adv_aceCPR_AED,1);
		};
	};
};

class ACE_Medical_Treatment_Actions {
	class BasicBandage;
	class CPR: BasicBandage {
		callbackSuccess = "adv_aceCPR_fnc_CPR_action";
		animationMedic = "AinvPknlMstpSnonWnonDr_medic0";
		animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
		animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon"};
	};
	class Defibrillator: CPR {
		displayName = "$STR_ADV_ACECPR_AED_ACTION";
		displayNameProgress = "$STR_ADV_ACECPR_AED_PROGRESS";
		icon = "\adv_aceCPR\ui\defib_action.paa";
		items[] = {"adv_aceCPR_AED"};
		condition = "[_medic, _patient] call adv_aceCPR_fnc_AED_condition";
		treatmentTime = 8;
		callbackSuccess = "adv_aceCPR_fnc_AED_action";
		callbackStart = "adv_aceCPR_fnc_AED_sound";
		callbackFailure = "adv_aceCPR_fnc_AED_cancelled";
		callbackProgress = "adv_aceCPR_fnc_AED_progress";
		animationMedic = "AinvPknlMstpSnonWnonDnon_medic3";
		treatmentLocations = "adv_aceCPR_useLocation_AED";
	};
	class Defibrillator_station: Defibrillator {
		items[] = {};
		condition = "[_medic, _patient] call adv_aceCPR_fnc_AED_station_condition";
		callbackSuccess = "adv_aceCPR_fnc_AED_station";
		callbackProgress = "";
		callbackFailure = "";
		animationMedic = "AinvPknlMstpSnonWnonDnon_medic3";
		treatmentLocations = 0;
	};
};
