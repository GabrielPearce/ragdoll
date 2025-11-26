/*
    GPR_Ragdoll_fnc_applyRagdoll
    - Runs on clients via remoteExec (see CfgRemoteExec)
    - _unit is the dead unit / ragdoll proxy
    - This is a SIMPLE placeholder; swap in original mod logic later
*/

params ["_unit"];

if (!hasInterface) exitWith {};
if (isNull _unit) exitWith {};

// Only run where the ragdoll is actually local
if (!local _unit) exitWith {};

diag_log format ["[GPR_Ragdoll] applyRagdoll on client %1 for unit %2", clientOwner, _unit];

// Basic "kick" based on last velocity + randomness
private _vel = velocity _unit;

private _impulse = [
    (_vel select 0) + (random 4 - 2),
    (_vel select 1) + (random 4 - 2),
    (_vel select 2) + (random 4 + 1)
];

// Apply the impulse to the corpse
_unit setVelocity _impulse;

// Optional: a second small nudge shortly after
[
    _unit,
    [
        (_impulse select 0) * 0.5,
        (_impulse select 1) * 0.5,
        (_impulse select 2) * 0.5
    ]
] spawn {
    params ["_u", "_imp"];

    uiSleep 0.05;
    if (!isNull _u) then {
        _u setVelocity _imp;
    };
};
