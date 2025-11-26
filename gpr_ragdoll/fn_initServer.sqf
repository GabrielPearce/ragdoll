/*
    GPR_Ragdoll_fnc_initServer
    - Runs on server (preInit = 1 in CfgFunctions)
    - Attaches Killed EHs to all human units
    - On death, tells clients to run GPR_Ragdoll_fnc_applyRagdoll
*/

if (!isServer) exitWith {};

diag_log "[GPR_Ragdoll] initServer preInit running on server";

// Global helper to add Killed EH to a unit
GPR_Ragdoll_fnc_addKilledEH = {
    params ["_unit"];

    if (isNull _unit) exitWith {};
    if (!(_unit isKindOf "CAManBase")) exitWith {};

    // Avoid stacking multiple EHs
    if (!isNil {_unit getVariable "GPR_Ragdoll_hasEH"}) exitWith {};

    _unit setVariable ["GPR_Ragdoll_hasEH", true];

    _unit addEventHandler ["Killed", {
        params ["_unit", "_killer", "_instigator", "_useEffects"];

        diag_log format ["[GPR_Ragdoll] Killed EH fired for %1", _unit];

        // Ask all clients to run the ragdoll effect for this unit
        [_unit] remoteExecCall ["GPR_Ragdoll_fnc_applyRagdoll", 0, _unit];
        // JIP ID = _unit, so late joiners can catch up if needed
    }];
};

// Add EH to all existing units
{
    [_x] call GPR_Ragdoll_fnc_addKilledEH;
} forEach allUnits;

// Add EH to newly created units
addMissionEventHandler ["EntityCreated", {
    params ["_entity"];

    if (_entity isKindOf "CAManBase") then {
        [_entity] call GPR_Ragdoll_fnc_addKilledEH;
    };
}];
