-- DB update 2026_07_16_00 -> 2026_07_16_01
-- Aerial Command Unit: hover height and flags to match TDB (hover-based chase)
-- 256 = UNIT_FLAG_IMMUNE_TO_PC (cleared by script at phase start), 512 = CREATURE_FLAG_EXTRA_NO_MOVE_FLAGS_UPDATE
UPDATE `creature_template` SET `HoverHeight` = 15, `unit_flags` = `unit_flags`|256, `flags_extra` = `flags_extra`|512 WHERE `entry` IN (33670, 34109);

-- Values ported from TrinityCore (TrinityCore/TrinityCore@7c13b383); zeroed combat reach
-- made the hovering ACU unreachable for Magnetic Core's 15y check
UPDATE `creature_model_info` SET `BoundingRadius` = 0.31, `CombatReach` = 5 WHERE `DisplayID` = 28979;

-- Waypoint update for NPC path (ID 828970)
DELETE FROM `waypoint_data` WHERE `id`=828970;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `velocity`, `delay`, `smoothTransition`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(828970, 1, 6526.62, -6539.96, 43.7632, NULL, 0, 0, 0, 0, 0, 100, 0),
(828970, 2, 6523.71, -6522.53, 43.7615, NULL, 0, 0, 0, 0, 0, 100, 0),
(828970, 3, 6525.49, -6516.23, 43.7615, NULL, 0, 0, 0, 0, 0, 100, 0),
(828970, 4, 6521.77, -6510.52, 43.7615, NULL, 0, 0, 0, 0, 0, 100, 0),
(828970, 5, 6513.87, -6511.71, 43.7615, NULL, 0, 0, 0, 0, 0, 100, 0),
(828970, 6, 6511.11, -6517.37, 43.7615, NULL, 0, 0, 0, 0, 0, 100, 0),
(828970, 7, 6515.04, -6523.84, 43.7615, NULL, 0, 0, 0, 0, 0, 100, 0),
(828970, 8, 6523.41, -6535.42, 43.7615, NULL, 0, 0, 0, 0, 0, 100, 0),
(828970, 9, 6520.24, -6541.45, 43.7615, NULL, 0, 0, 0, 0, 0, 100, 0),
(828970, 10, 6516.43, -6545.24, 43.7615, NULL, 0, 0, 0, 0, 0, 100, 0),
(828970, 11, 6514.04, -6546.91, 43.7615, NULL, 0, 0, 0, 0, 0, 100, 0),
(828970, 12, 6510.9, -6546.01, 43.7615, NULL, 0, 0, 0, 0, 0, 100, 0),
(828970, 13, 6501.8, -6539.64, 43.7615, NULL, 0, 0, 0, 0, 0, 100, 0),
(828970, 14, 6497.73, -6534.6, 43.7615, NULL, 0, 0, 0, 0, 0, 100, 0),
(828970, 15, 6489.84, -6525.79, 43.7615, NULL, 0, 0, 0, 0, 0, 100, 0),
(828970, 16, 6491.16, -6514.36, 43.7636, NULL, 0, 0, 0, 0, 0, 100, 0),
(828970, 17, 6494.49, -6499.21, 43.762, NULL, 0, 0, 0, 0, 0, 100, 0),
(828970, 18, 6498.01, -6496.25, 43.762, NULL, 0, 0, 0, 0, 0, 100, 0),
(828970, 19, 6514.92, -6489, 43.762, NULL, 0, 0, 0, 0, 0, 100, 0),
(828970, 20, 6523.63, -6487.37, 43.762, NULL, 0, 0, 0, 0, 0, 100, 0),
(828970, 21, 6542.33, -6502.09, 43.7639, NULL, 0, 0, 0, 0, 0, 100, 0),
(828970, 22, 6547.08, -6509.47, 43.7625, NULL, 0, 0, 0, 0, 0, 100, 0),
(828970, 23, 6544.49, -6525.22, 43.7625, NULL, 0, 0, 0, 0, 0, 100, 0),
(828970, 24, 6541.54, -6535.81, 43.7625, NULL, 0, 0, 0, 0, 0, 100, 0);
-- 16320