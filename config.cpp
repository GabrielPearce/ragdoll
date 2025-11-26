class CfgPatches
{
	class VD_RFX_DRA
	{
		units[]={};
		requiredVersion=1;
		requiredAddons[]=
		{
			"A3_Modules_F"
		};
	};
};
class PhysXMaterials
{
	class PhysXMaterialBase
	{
		isDefault="false";
		isAnisotropic="false";
		restitution=0.050000001;
		staticFriction=0.75;
		dynamicFriction=0.55000001;
	};
	class Ragdoll: PhysXMaterialBase
	{
		restitution=0.64999998;
		staticFriction=0.55000001;
		dynamicFriction=0.75;
	};
};
class PhysXParams
{
	epeImpulseDamageCoef=3;
	impulseForceRagdollCoef=150;
	impulseTorqueRagdollCoef=75;
	impulseSpeedRagdollCoef=10;
	maxRagdollImpulseForceMagnitude=100;
	maxRagdollImpulseTorqueMagnitude=50;
	ragdollUnderwaterForceCoef=9.6000004;
	ragdollUnderwaterInitImpulseCoef=0.98000002;
	ragdollUnderwaterBuoyancyCoef=9.6999998;
	ragdollUnderwaterResistanceCoef=0.15000001;
	ragdollOnCollideSpeedLimit=4;
	ragdollOnCollideMassLimit=200;
	ragdollOnCollideForceCoef=0.1;
	ragdollOnCollideMaxForce=1;
	ragdollOnCollideMaxOffset=10;
	ragdollOnCollideMaxOffsetSpeed=100;
	ragdollHitTime=0.1;
	ragdollHitForceCoef=0.0099999998;
	ragdollHitDmgLimit=0.60000002;
	ragdollVehicleCollision=1;
	wheelPointRejectLimitSpeed=5;
	wheelPointRejectAngle="Pi/4.0";
	wheelPointRejectAngleFast="Pi/3.0";
	wheelNormalRejectAngle="Pi/4.0";
	wheelNormalRejectAngleFast="Pi/2.4";
};
class RagDollDefaultLimit
{
	value=5;
	restitution=1;
	hardness=0.1;
};
class RagDollDefaultSpring
{
	enabled=1;
	value=5;
	damper=0;
	targetValue=0;
};
class RagDollSphericalJoint
{
	class TwistLimitLow: RagDollDefaultLimit
	{
	};
	class TwistLimitHigh: RagDollDefaultLimit
	{
	};
	class SwingLimit: RagDollDefaultLimit
	{
	};
	class TwistSpring: RagDollDefaultSpring
	{
		enabled=1;
		damper=0;
	};
	class SwingSpring: RagDollDefaultSpring
	{
		enabled=1;
		damper=0;
	};
	class JointSpring: RagDollDefaultSpring
	{
		enabled=1;
		damper=0;
	};
	type="spherical";
	enableCollision=1;
	projectionDistance=0;
	projectionMode="point";
};
class RagDollRevoluteJoint
{
	class LimitLow: RagDollDefaultLimit
	{
	};
	class LimitHigh: RagDollDefaultLimit
	{
	};
	class Spring: RagDollDefaultSpring
	{
		enabled=1;
	};
	type="revolute";
	enableCollision=1;
	projectionDistance=0;
	projectionMode="point";
};
class RagDollD6Joint_PX3
{
	type="D6";
	enableCollision=0;
	projectionDistance=0;
	projectionMode="point";
	swingLimitY=10;
	swingLimitZ=10;
	swingSpring=0;
	swingDamping=0;
	swingRestitution=0.30000001;
	swingContactDistance=0.75;
	twistLimitLower=90;
	twistLimitUpper=90;
	twistSpring=0;
	twistDamping=0;
	twistRestitution=0.40000001;
	twistContactDistance=0.75;
	driveSpring=0;
	driveDamping=100;
	driveMaxForce=100;
	driveUseAcceleration=1;
	driveLinearVelocity[]={0,0,0};
	driveAngularVelocity[]={-12,0,0};
};
class CfgRagDollSkeletons
{
	class BaseRagdoll
	{
		primaryWeaponBone="";
		secondaryWeaponBone="";
		weaponSleepLinearVelocity=0.1;
		weaponSleepAngularVelocity=0.1;
		weaponDropMinTime=1;
		weaponDropMaxTime=3;
		weaponDistanceLimit=0.1;
		weaponDistanceLimitTime=2;
		sleepLinearVelocity=0.1;
		sleepAngularVelocity=0.1;
		simulateMinTime=10;
		simulateMaxTime=30;
		simulateDistanceLimit=0.5;
		simulateDistanceLimitTime=2;
		recoveryBlendTime=0.0099999998;
		recoveryCosLimit=-1;
		recoveryDistLimit=100;
		animBlendTime=0;
	};
	class Soldier: BaseRagdoll
	{
		primaryWeaponBone="weapon";
		secondaryWeaponBone="launcher";
		draggingMask="dragging";
		hitMask="hit";
		class WeaponLinkBones
		{
			class LinkBone1
			{
				bone="leftHand";
				canBeDropped=1;
				prefference=1;
			};
			class LinkBone2
			{
				bone="rightHand";
				canBeDropped=1;
				prefference=1;
			};
			class LinkBone3
			{
				bone="chest";
				canBeDropped=1;
				prefference=2;
			};
		};
		class Masks
		{
			class DraggingMask
			{
				name="dragging";
				mask[]=
				{
					
					{
						"pelvis",
						0,
						1
					},
					
					{
						"spine1",
						0,
						1
					},
					
					{
						"chest",
						0,
						1
					},
					
					{
						"head",
						1,
						0
					},
					
					{
						"neck",
						0,
						1
					},
					
					{
						"leftShoulder",
						1,
						0
					},
					
					{
						"leftArm",
						1,
						0
					},
					
					{
						"leftForeArm",
						1,
						0
					},
					
					{
						"leftHand",
						1,
						0
					},
					
					{
						"rightShoulder",
						1,
						0
					},
					
					{
						"rightArm",
						1,
						0
					},
					
					{
						"rightForeArm",
						1,
						0
					},
					
					{
						"rightHand",
						1,
						0
					},
					
					{
						"leftUpLeg",
						1,
						0
					},
					
					{
						"leftLeg",
						1,
						0
					},
					
					{
						"leftFoot",
						1,
						0
					},
					
					{
						"rightUpLeg",
						1,
						0
					},
					
					{
						"rightLeg",
						1,
						0
					},
					
					{
						"rightFoot",
						1,
						0
					},
					
					{
						"weapon",
						0.2,
						1
					},
					
					{
						"launcher",
						0,
						1
					}
				};
			};
			class HitMask
			{
				name="hit";
				mask[]=
				{
					
					{
						"pelvis",
						0,
						1
					},
					
					{
						"spine1",
						0,
						1
					},
					
					{
						"chest",
						1,
						0
					},
					
					{
						"head",
						1,
						0
					},
					
					{
						"neck",
						0,
						1
					},
					
					{
						"leftShoulder",
						1,
						0
					},
					
					{
						"leftArm",
						1,
						0
					},
					
					{
						"leftForeArm",
						1,
						0
					},
					
					{
						"leftHand",
						1,
						0
					},
					
					{
						"rightShoulder",
						1,
						0
					},
					
					{
						"rightArm",
						1,
						0
					},
					
					{
						"rightForeArm",
						1,
						0
					},
					
					{
						"rightHand",
						1,
						0
					},
					
					{
						"leftUpLeg",
						0,
						1
					},
					
					{
						"leftLeg",
						0,
						1
					},
					
					{
						"leftFoot",
						0,
						1
					},
					
					{
						"rightUpLeg",
						0,
						1
					},
					
					{
						"rightLeg",
						0,
						1
					},
					
					{
						"rightFoot",
						0,
						1
					},
					
					{
						"weapon",
						0,
						1
					},
					
					{
						"launcher",
						0,
						1
					}
				};
			};
		};
		class BaseRagdollBone
		{
			material="Ragdoll";
			childrenUseStartTrans=1;
		};
		class Bones
		{
			class Pelvis: BaseRagdollBone
			{
				name="pelvis";
				type="sphere";
				startBone="pelvis";
				endBone="spine1";
				offset[]={0,0,0};
				mass=16;
				radius=0.14;
			};
			class Spine1: BaseRagdollBone
			{
				name="spine1";
				type="capsule";
				startBone="spine1";
				endBone="spine2";
				mass=12;
			};
			class Chest: BaseRagdollBone
			{
				name="chest";
				type="sphere";
				startBone="spine2";
				endBone="neck";
				offset[]={0,0,0};
				mass=12;
				radius=0.13;
			};
			class Neck: BaseRagdollBone
			{
				name="neck";
				type="capsule";
				startBone="neck";
				endBone="head";
				mass=6;
			};
			class Head: BaseRagdollBone
			{
				name="head";
				type="sphere";
				startBone="head";
				offset[]={0,0,0};
				mass=12;
				radius=0.13;
			};
			class LeftShoulder: BaseRagdollBone
			{
				name="leftShoulder";
				type="capsule";
				startBone="leftShoulder";
				endBone="leftArm";
				mass=8;
			};
			class LeftArm: BaseRagdollBone
			{
				name="leftArm";
				type="capsule";
				startBone="leftArm";
				endBone="leftForeArm";
				mass=5;
			};
			class LeftForeArm: BaseRagdollBone
			{
				name="leftForeArm";
				type="capsule";
				startBone="leftForeArm";
				endBone="leftHand";
				mass=3;
			};
			class LeftHand: BaseRagdollBone
			{
				name="leftHand";
				type="sphere";
				startBone="leftHand";
				mass=1;
				radius=0.079999998;
				childrenUseStartTrans=0;
			};
			class RightShoulder: BaseRagdollBone
			{
				name="rightShoulder";
				type="capsule";
				startBone="rightShoulder";
				endBone="rightArm";
				mass=8;
			};
			class RightArm: BaseRagdollBone
			{
				name="rightArm";
				type="capsule";
				startBone="rightArm";
				endBone="rightForeArm";
				mass=5;
			};
			class RightForeArm: BaseRagdollBone
			{
				name="rightForeArm";
				type="capsule";
				startBone="rightForeArm";
				endBone="rightHand";
				mass=3;
			};
			class RightHand: BaseRagdollBone
			{
				name="rightHand";
				type="sphere";
				startBone="rightHand";
				mass=1;
				radius=0.079999998;
				childrenUseStartTrans=0;
			};
			class LeftUpLeg: BaseRagdollBone
			{
				name="leftUpLeg";
				type="capsule";
				startBone="leftUpLeg";
				endBone="leftLeg";
				mass=8;
			};
			class LeftLeg: BaseRagdollBone
			{
				name="leftLeg";
				type="capsule";
				startBone="leftLeg";
				endBone="leftFoot";
				mass=6;
			};
			class LeftFoot: BaseRagdollBone
			{
				name="leftFoot";
				type="box";
				startBone="leftFoot";
				size[]={0.15000001,0.050000001,0.07};
				mass=2;
			};
			class RightUpLeg: BaseRagdollBone
			{
				name="rightUpLeg";
				type="capsule";
				startBone="rightUpLeg";
				endBone="rightLeg";
				mass=8;
			};
			class RightLeg: BaseRagdollBone
			{
				name="rightLeg";
				type="capsule";
				startBone="rightLeg";
				endBone="rightFoot";
				mass=6;
			};
			class RightFoot: BaseRagdollBone
			{
				name="rightFoot";
				type="box";
				startBone="rightFoot";
				size[]={0.15000001,0.050000001,0.07};
				mass=2;
			};
			class Weapon: BaseRagdollBone
			{
				name="weapon";
				type="weapon";
				startBone="weapon";
				endPosRelToStart[]={0,0,0.40000001};
				mass=4;
			};
			class Launcher: BaseRagdollBone
			{
				name="launcher";
				type="weapon";
				startBone="launcher";
				endPosRelToStart[]={0,0,0.40000001};
				mass=9;
			};
		};
		class JointsPX3
		{
			class Pelvis_Chest_PX3: RagDollD6Joint_PX3
			{
				name="pelvis_spine1";
				bone1="pelvis";
				bone2="spine1";
				enableCollision=0;
				swingLimitY=25;
				swingLimitZ=15;
				twistLimitLower=-35;
				twistLimitUpper=35;
				swingSpring=0;
				swingDamping=0;
				twistSpring=0;
				twistDamping=0;
				driveSpring=550;
				driveDamping=1500;
				driveSpringWater=5;
				driveDampingWater=5;
				driveAngularVelocity[]={-40,0,0};
			};
			class Spine1_Spine2_PX3: RagDollD6Joint_PX3
			{
				name="spine1_spine2";
				bone1="spine1";
				bone2="chest";
				axis[]={0,1,0.30000001};
				enableCollision=0;
				swingLimitY=15;
				swingLimitZ=15;
				twistLimitLower=-10;
				twistLimitUpper=10;
				swingSpring=0;
				swingDamping=0;
				twistSpring=0;
				twistDamping=0;
				driveSpring=550;
				driveDamping=30;
				driveSpringWater=5;
				driveDampingWater=5;
				driveAngularVelocity[]={-50,0,0};
			};
			class Spine2_Neck_PX3: RagDollD6Joint_PX3
			{
				name="spine2_neck";
				bone1="chest";
				bone2="neck";
				enableCollision=0;
				swingLimitY=20;
				swingLimitZ=45;
				twistLimitLower=-60;
				twistLimitUpper=60;
				swingSpring=0;
				swingDamping=0;
				twistSpring=0;
				twistDamping=0;
				swingRestitution=1;
				twistRestitution=1;
				driveSpring=150;
				driveDamping=300;
				driveSpringWater=1;
				driveDampingWater=3;
				driveAngularVelocity[]={0,0,0};
			};
			class Chest_Head_PX3: RagDollD6Joint_PX3
			{
				name="neck_head";
				bone1="neck";
				bone2="head";
				enableCollision=0;
				swingLimitY=0;
				swingLimitZ=30;
				twistLimitLower=0;
				twistLimitUpper=0;
				swingSpring=0;
				swingDamping=0;
				twistSpring=0;
				twistDamping=0;
				swingRestitution=1;
				twistRestitution=1;
				driveSpring=150;
				driveDamping=200;
				driveSpringWater=1;
				driveDampingWater=3;
				driveAngularVelocity[]={0,0,0};
			};
			class Chest_LeftArm_PX3: RagDollD6Joint_PX3
			{
				name="chest_leftShoulder";
				bone1="chest";
				bone2="leftShoulder";
				enableCollision=1;
				swingLimitY=30;
				swingLimitZ=30;
				twistLimitLower=-30;
				twistLimitUpper=30;
				swingContactDistance=0.44999999;
				twistContactDistance=0.050000001;
				swingSpring=0;
				swingDamping=0;
				twistSpring=0;
				twistDamping=0;
				swingRestitution=1;
				twistRestitution=1;
				driveSpring=50;
				driveDamping=100;
				driveSpringWater=3;
				driveDampingWater=3;
				driveAngularVelocity[]={2,1,6};
			};
			class LeftShoulder_LeftArm_PX3: RagDollD6Joint_PX3
			{
				name="leftShoulder_leftArm";
				bone1="leftShoulder";
				bone2="leftArm";
				enableCollision=1;
				swingLimitY=30;
				swingLimitZ=140;
				twistLimitLower=-20;
				twistLimitUpper=20;
				swingContactDistance=0.050000001;
				twistContactDistance=0.050000001;
				swingSpring=0;
				swingDamping=0;
				twistSpring=0;
				twistDamping=0;
				swingRestitution=1;
				twistRestitution=1;
				driveSpring=150;
				driveDamping=100;
				driveSpringWater=3;
				driveDampingWater=3;
				driveAngularVelocity[]={-80,1,0};
			};
			class Chest_RightArm_PX3: RagDollD6Joint_PX3
			{
				name="chest_rightShoulder";
				bone1="chest";
				bone2="rightShoulder";
				enableCollision=1;
				swingLimitY=30;
				swingLimitZ=30;
				twistLimitLower=-30;
				twistLimitUpper=30;
				swingContactDistance=0.44999999;
				twistContactDistance=0.050000001;
				swingSpring=0;
				swingDamping=0;
				twistSpring=0;
				twistDamping=0;
				swingRestitution=1;
				twistRestitution=1;
				driveSpring=50;
				driveDamping=100;
				driveSpringWater=3;
				driveDampingWater=3;
				driveAngularVelocity[]={2,1,6};
			};
			class RightShoulder_RightArm_PX3: RagDollD6Joint_PX3
			{
				name="rightShoulder_rightArm";
				bone1="rightShoulder";
				bone2="rightArm";
				enableCollision=1;
				swingLimitY=30;
				swingLimitZ=140;
				twistLimitLower=-20;
				twistLimitUpper=20;
				swingContactDistance=0.050000001;
				twistContactDistance=0.050000001;
				swingSpring=0;
				swingDamping=0;
				twistSpring=0;
				twistDamping=0;
				swingRestitution=1;
				twistRestitution=1;
				driveSpring=150;
				driveDamping=100;
				driveSpringWater=3;
				driveDampingWater=3;
				driveAngularVelocity[]={80,1,0};
			};
			class Pelvis_LeftUpLeg_PX3: RagDollD6Joint_PX3
			{
				name="pelvis_leftUpLeg";
				bone1="pelvis";
				bone2="leftUpLeg";
				axis[]={1,0,0};
				enableCollision=1;
				swingLimitY=36;
				swingLimitZ=31;
				twistLimitLower=-120;
				twistLimitUpper=30;
				swingSpring=0;
				swingDamping=0;
				twistSpring=0;
				twistDamping=0;
				driveSpring=600;
				driveDamping=150;
				driveUseAcceleration=1;
				swingRestitution=1;
				twistRestitution=1;
				driveSpringWater=3;
				driveDampingWater=3;
				driveAngularVelocity[]={-4,0,1};
			};
			class Pelvis_RightUpLeg_PX3: RagDollD6Joint_PX3
			{
				name="pelvis_rightUpLeg";
				bone1="pelvis";
				bone2="rightUpLeg";
				axis[]={1,0,0};
				enableCollision=1;
				swingLimitY=36;
				swingLimitZ=31;
				twistLimitLower=-120;
				twistLimitUpper=30;
				swingSpring=0;
				swingDamping=0;
				twistSpring=0;
				twistDamping=0;
				driveSpring=600;
				driveDamping=150;
				driveUseAcceleration=1;
				swingRestitution=1;
				twistRestitution=1;
				driveSpringWater=3;
				driveDampingWater=3;
				driveAngularVelocity[]={-4,0,-1};
			};
			class LeftUpLeg_LeftLeg_PX3: RagDollD6Joint_PX3
			{
				name="leftUpLeg_leftLeg";
				bone1="leftUpLeg";
				bone2="leftLeg";
				enableCollision=0;
				axis[]={1,0,0};
				swingLimitY=1;
				swingLimitZ=15;
				twistLimitLower=0;
				twistLimitUpper=130;
				swingSpring=0;
				swingDamping=0;
				twistSpring=3000;
				twistDamping=50;
				swingRestitution=1;
				twistRestitution=1;
				driveSpring=50;
				driveDamping=10;
				driveMaxForce=1000;
				driveUseAcceleration=1;
				driveSpringWater=2;
				driveDampingWater=2;
				swingContactDistance=0.050000001;
				twistContactDistance=0.050000001;
				driveAngularVelocity[]={0,0,0};
			};
			class RightUpLeg_RightLeg_PX3: RagDollD6Joint_PX3
			{
				name="rightUpLeg_rightLeg";
				bone1="rightUpLeg";
				bone2="rightLeg";
				enableCollision=0;
				axis[]={1,0,0};
				swingLimitY=1;
				swingLimitZ=15;
				twistLimitLower=0;
				twistLimitUpper=130;
				swingSpring=0;
				swingDamping=0;
				twistSpring=3000;
				twistDamping=50;
				swingRestitution=1;
				twistRestitution=1;
				driveSpring=50;
				driveDamping=10;
				driveMaxForce=1000;
				driveUseAcceleration=1;
				driveSpringWater=2;
				driveDampingWater=2;
				swingContactDistance=0.050000001;
				twistContactDistance=0.050000001;
				driveAngularVelocity[]={0,0,0};
			};
			class LeftArm_LeftForeArm_PX3: RagDollD6Joint_PX3
			{
				name="leftArm_leftForeArm";
				bone1="leftArm";
				bone2="leftForeArm";
				enableCollision=0;
				axis[]={-1,1,-0.2};
				swingLimitY=10;
				swingLimitZ=10;
				twistLimitLower=-5;
				twistLimitUpper=150;
				driveSpring=100;
				driveDamping=100;
				driveSpringWater=1;
				driveDampingWater=1;
				driveAngularVelocity[]={6,0,-50};
			};
			class RightArm_RightForeArm_PX3: RagDollD6Joint_PX3
			{
				name="rightArm_rightForeArm";
				bone1="rightArm";
				bone2="rightForeArm";
				enableCollision=0;
				axis[]={-1,-1,0.2};
				swingLimitY=10;
				swingLimitZ=10;
				twistLimitLower=-5;
				twistLimitUpper=150;
				driveSpring=100;
				driveDamping=100;
				driveSpringWater=1;
				driveDampingWater=1;
				driveAngularVelocity[]={6,0,50};
			};
			class LeftForeArm_LeftHand_PX3: RagDollD6Joint_PX3
			{
				name="leftForeArm_leftHand";
				bone1="leftForeArm";
				bone2="leftHand";
				enableCollision=1;
				swingLimitY=45;
				swingLimitZ=45;
				twistLimitLower=-50;
				twistLimitUpper=50;
				driveSpring=25;
				driveDamping=50;
				driveSpringWater=1;
				driveDampingWater=1;
			};
			class RightForeArm_RightHand_PX3: RagDollD6Joint_PX3
			{
				name="rightForeArm_rightHand";
				bone1="rightForeArm";
				bone2="rightHand";
				enableCollision=1;
				swingLimitY=45;
				swingLimitZ=45;
				twistLimitLower=-50;
				twistLimitUpper=50;
				driveSpring=25;
				driveDamping=50;
				driveSpringWater=1;
				driveDampingWater=1;
			};
			class LeftLeg_LeftFoot_PX3: RagDollD6Joint_PX3
			{
				name="leftLeg_leftFoot";
				bone1="leftLeg";
				bone2="leftFoot";
				axis[]={1,0,0};
				enableCollision=1;
				swingLimitY=5;
				swingLimitZ=15;
				twistLimitLower=-15;
				twistLimitUpper=45;
				swingSpring=1200;
				swingDamping=150;
				twistSpring=600;
				twistDamping=50;
				driveSpring=1;
				driveDamping=30;
				driveSpringWater=2;
				driveDampingWater=2;
				driveAngularVelocity[]={3,0,0};
			};
			class RightLeg_RightFoot_PX3: RagDollD6Joint_PX3
			{
				name="rightLeg_rightFoot";
				bone1="rightLeg";
				bone2="rightFoot";
				axis[]={1,0,0};
				enableCollision=1;
				swingLimitY=5;
				swingLimitZ=15;
				twistLimitLower=-15;
				twistLimitUpper=45;
				swingSpring=1200;
				swingDamping=150;
				twistSpring=600;
				twistDamping=50;
				driveSpring=1;
				driveDamping=30;
				driveSpringWater=2;
				driveDampingWater=2;
				driveAngularVelocity[]={3,0,0};
			};
		};
	};
};
class cfgMods
{
	author="venomDeejays";
	timepacked="1632411863";
};
