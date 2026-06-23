/*
 * This file is part of the AzerothCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Affero General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Chat.h"
#include "ItemScript.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "GossipDef.h"
#include "ScriptedGossip.h"

class TeleportBook : public ItemScript
{
public:
    TeleportBook() : ItemScript("TeleportBook") {}

    bool OnUse(Player* player, Item* item, SpellCastTargets const& /*targets*/) override
    {
        ShowMainMenu(player,item);
        return true;
    }

private:
    void ShowMainMenu(Player* player,Item* item)
    {
        ClearGossipMenuFor(player);

        // GM 可以访问所有区域
        if (player->IsGameMaster()) {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "东部王国 - 北部", GOSSIP_SENDER_MAIN, 1);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "东部王国 - 南部", GOSSIP_SENDER_MAIN, 2);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "卡利姆多", GOSSIP_SENDER_MAIN, 3);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "外域", GOSSIP_SENDER_MAIN, 4);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "诺森德 - 联盟区域", GOSSIP_SENDER_MAIN, 5);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "诺森德 - 部落区域", GOSSIP_SENDER_MAIN, 6);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "战场", GOSSIP_SENDER_MAIN, 7);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "副本 - 东部王国", GOSSIP_SENDER_MAIN, 8);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "副本 - 卡利姆多", GOSSIP_SENDER_MAIN, 9);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "副本 - 外域", GOSSIP_SENDER_MAIN, 10);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "副本 - 诺森德", GOSSIP_SENDER_MAIN, 11);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "其他区域", GOSSIP_SENDER_MAIN, 12);
        }
        // 联盟玩家
        else if (player->GetTeamId() == TEAM_ALLIANCE) {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "联盟主城", GOSSIP_SENDER_MAIN, 100);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "东部王国 - 联盟区域", GOSSIP_SENDER_MAIN, 1);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "卡利姆多 - 联盟区域", GOSSIP_SENDER_MAIN, 3);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "外域 - 联盟区域", GOSSIP_SENDER_MAIN, 4);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "诺森德 - 联盟区域", GOSSIP_SENDER_MAIN, 5);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "战场", GOSSIP_SENDER_MAIN, 7);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "副本 - 联盟区域", GOSSIP_SENDER_MAIN, 8);
        }
        // 部落玩家
        else {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "部落主城", GOSSIP_SENDER_MAIN, 200);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "东部王国 - 部落区域", GOSSIP_SENDER_MAIN, 2);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "卡利姆多 - 部落区域", GOSSIP_SENDER_MAIN, 3);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "外域 - 部落区域", GOSSIP_SENDER_MAIN, 4);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "诺森德 - 部落区域", GOSSIP_SENDER_MAIN, 6);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "战场", GOSSIP_SENDER_MAIN, 7);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "副本 - 部落区域", GOSSIP_SENDER_MAIN, 9);
        }

        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, item->GetGUID());
    }

    void ShowContinentMenu(Player* player, Item* item, uint32 continentId)
    {
        ClearGossipMenuFor(player);

        switch (continentId)
        {
            // 东部王国 - 北部 (联盟)
            case 1:
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "暴风城", GOSSIP_SENDER_MAIN, 101);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "铁炉堡", GOSSIP_SENDER_MAIN, 102);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "达纳苏斯", GOSSIP_SENDER_MAIN, 103);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "艾尔文森林", GOSSIP_SENDER_MAIN, 104);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "西部荒野", GOSSIP_SENDER_MAIN, 105);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "赤脊山", GOSSIP_SENDER_MAIN, 106);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "暮色森林", GOSSIP_SENDER_MAIN, 107);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "荆棘谷", GOSSIP_SENDER_MAIN, 108);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "希尔斯布莱德丘陵", GOSSIP_SENDER_MAIN, 109);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "奥特兰克山脉", GOSSIP_SENDER_MAIN, 110);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "西瘟疫之地", GOSSIP_SENDER_MAIN, 111);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "东瘟疫之地", GOSSIP_SENDER_MAIN, 112);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "提瑞斯法林地", GOSSIP_SENDER_MAIN, 113);
                break;
            
            // 东部王国 - 南部 (部落)
            case 2:
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "幽暗城", GOSSIP_SENDER_MAIN, 201);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "银月城", GOSSIP_SENDER_MAIN, 202);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "永歌森林", GOSSIP_SENDER_MAIN, 203);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "幽魂之地", GOSSIP_SENDER_MAIN, 204);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "奎尔丹纳斯岛", GOSSIP_SENDER_MAIN, 205);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "提瑞斯法林地", GOSSIP_SENDER_MAIN, 206);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "银松森林", GOSSIP_SENDER_MAIN, 207);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "希尔斯布莱德丘陵", GOSSIP_SENDER_MAIN, 208);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "辛特兰", GOSSIP_SENDER_MAIN, 209);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "阿拉希高地", GOSSIP_SENDER_MAIN, 210);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "荒芜之地", GOSSIP_SENDER_MAIN, 211);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "灼热峡谷", GOSSIP_SENDER_MAIN, 212);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "燃烧平原", GOSSIP_SENDER_MAIN, 213);
                break;
            
            // 卡利姆多 (按阵营分类)
            case 3:
                if (player->GetTeamId() == TEAM_ALLIANCE) {
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "达纳苏斯", GOSSIP_SENDER_MAIN, 301);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "泰达希尔", GOSSIP_SENDER_MAIN, 302);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "黑海岸", GOSSIP_SENDER_MAIN, 303);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "灰谷", GOSSIP_SENDER_MAIN, 304);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "石爪山脉", GOSSIP_SENDER_MAIN, 305);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "凄凉之地", GOSSIP_SENDER_MAIN, 306);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "菲拉斯", GOSSIP_SENDER_MAIN, 307);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "羽月要塞", GOSSIP_SENDER_MAIN, 308);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "塔纳利斯", GOSSIP_SENDER_MAIN, 309);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "安戈洛环形山", GOSSIP_SENDER_MAIN, 310);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "希利苏斯", GOSSIP_SENDER_MAIN, 311);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "冬泉谷", GOSSIP_SENDER_MAIN, 312);
                } else {
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "奥格瑞玛", GOSSIP_SENDER_MAIN, 351);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "雷霆崖", GOSSIP_SENDER_MAIN, 352);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "杜隆塔尔", GOSSIP_SENDER_MAIN, 353);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "贫瘠之地", GOSSIP_SENDER_MAIN, 354);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "莫高雷", GOSSIP_SENDER_MAIN, 355);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "尘泥沼泽", GOSSIP_SENDER_MAIN, 356);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "凄凉之地", GOSSIP_SENDER_MAIN, 357);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "菲拉斯", GOSSIP_SENDER_MAIN, 358);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "塔纳利斯", GOSSIP_SENDER_MAIN, 359);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "安戈洛环形山", GOSSIP_SENDER_MAIN, 360);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "希利苏斯", GOSSIP_SENDER_MAIN, 361);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "冬泉谷", GOSSIP_SENDER_MAIN, 362);
                }
                break;
            
            // 外域 (按阵营分类)
            case 4:
                if (player->GetTeamId() == TEAM_ALLIANCE) {
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "荣耀堡", GOSSIP_SENDER_MAIN, 401);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "沙塔斯城", GOSSIP_SENDER_MAIN, 402);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "泰罗卡森林 - 奥蕾莉亚要塞", GOSSIP_SENDER_MAIN, 403);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "赞加沼泽 - 泰雷多尔", GOSSIP_SENDER_MAIN, 404);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "刀锋山 - 希尔瓦纳", GOSSIP_SENDER_MAIN, 405);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "纳格兰", GOSSIP_SENDER_MAIN, 406);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "虚空风暴", GOSSIP_SENDER_MAIN, 407);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "影月谷 - 蛮锤要塞", GOSSIP_SENDER_MAIN, 408);
                } else {
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "萨尔玛", GOSSIP_SENDER_MAIN, 451);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "沙塔斯城", GOSSIP_SENDER_MAIN, 452);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "泰罗卡森林 - 裂石堡", GOSSIP_SENDER_MAIN, 453);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "赞加沼泽 - 萨布拉金", GOSSIP_SENDER_MAIN, 454);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "刀锋山 - 雷神要塞", GOSSIP_SENDER_MAIN, 455);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "纳格兰", GOSSIP_SENDER_MAIN, 456);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "虚空风暴", GOSSIP_SENDER_MAIN, 457);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "影月谷 - 影月村", GOSSIP_SENDER_MAIN, 458);
                }
                break;
            
            // 诺森德 - 联盟区域
            case 5:
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "北风苔原 - 无畏要塞", GOSSIP_SENDER_MAIN, 501);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "嚎风峡湾 - 瓦加德", GOSSIP_SENDER_MAIN, 502);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "龙骨荒野 - 暮冬要塞", GOSSIP_SENDER_MAIN, 503);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "灰熊丘陵 - 琥珀松木营地", GOSSIP_SENDER_MAIN, 504);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "祖达克 - 银色前沿", GOSSIP_SENDER_MAIN, 505);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "索拉查盆地 - 奈辛瓦里营地", GOSSIP_SENDER_MAIN, 506);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "风暴峭壁 - K3", GOSSIP_SENDER_MAIN, 507);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "冰冠冰川 - 银色前线基地", GOSSIP_SENDER_MAIN, 508);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "达拉然", GOSSIP_SENDER_MAIN, 509);
                break;
            
            // 诺森德 - 部落区域
            case 6:
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "北风苔原 - 战歌要塞", GOSSIP_SENDER_MAIN, 601);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "嚎风峡湾 - 复仇港", GOSSIP_SENDER_MAIN, 602);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "龙骨荒野 - 阿格玛之锤", GOSSIP_SENDER_MAIN, 603);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "灰熊丘陵 - 征服堡", GOSSIP_SENDER_MAIN, 604);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "祖达克 - 圣光据点", GOSSIP_SENDER_MAIN, 605);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "索拉查盆地 - 奈辛瓦里营地", GOSSIP_SENDER_MAIN, 606);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "风暴峭壁 - 格罗玛什坠毁点", GOSSIP_SENDER_MAIN, 607);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "冰冠冰川 - 暗影拱顶", GOSSIP_SENDER_MAIN, 608);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "达拉然", GOSSIP_SENDER_MAIN, 609);
                break;
            
            // 战场
            case 7:
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "奥特兰克山谷", GOSSIP_SENDER_MAIN, 701);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "战歌峡谷", GOSSIP_SENDER_MAIN, 702);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "阿拉希盆地", GOSSIP_SENDER_MAIN, 703);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "风暴之眼", GOSSIP_SENDER_MAIN, 704);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "远古海滩", GOSSIP_SENDER_MAIN, 705);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "征服之岛", GOSSIP_SENDER_MAIN, 706);
                break;
            
            // 副本 - 东部王国
            case 8:
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "死亡矿井", GOSSIP_SENDER_MAIN, 801);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "监狱", GOSSIP_SENDER_MAIN, 802);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "血色修道院", GOSSIP_SENDER_MAIN, 803);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "通灵学院", GOSSIP_SENDER_MAIN, 804);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "斯坦索姆", GOSSIP_SENDER_MAIN, 805);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "黑石深渊", GOSSIP_SENDER_MAIN, 806);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "黑石塔", GOSSIP_SENDER_MAIN, 807);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "熔火之心", GOSSIP_SENDER_MAIN, 808);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "黑翼之巢", GOSSIP_SENDER_MAIN, 809);
                break;
            
            // 副本 - 卡利姆多
            case 9:
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "怒焰裂谷", GOSSIP_SENDER_MAIN, 901);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "哀嚎洞穴", GOSSIP_SENDER_MAIN, 902);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "剃刀沼泽", GOSSIP_SENDER_MAIN, 903);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "剃刀高地", GOSSIP_SENDER_MAIN, 904);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "黑暗深渊", GOSSIP_SENDER_MAIN, 905);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "奥达曼", GOSSIP_SENDER_MAIN, 906);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "玛拉顿", GOSSIP_SENDER_MAIN, 907);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "祖尔法拉克", GOSSIP_SENDER_MAIN, 908);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "厄运之槌", GOSSIP_SENDER_MAIN, 909);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "安其拉废墟", GOSSIP_SENDER_MAIN, 910);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "安其拉神殿", GOSSIP_SENDER_MAIN, 911);
                break;
            
            // 副本 - 外域
            case 10:
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "地狱火城墙", GOSSIP_SENDER_MAIN, 1001);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "鲜血熔炉", GOSSIP_SENDER_MAIN, 1002);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "破碎大厅", GOSSIP_SENDER_MAIN, 1003);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "奴隶围栏", GOSSIP_SENDER_MAIN, 1004);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "幽暗沼泽", GOSSIP_SENDER_MAIN, 1005);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "蒸汽地窟", GOSSIP_SENDER_MAIN, 1006);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "暗影迷宫", GOSSIP_SENDER_MAIN, 1007);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "奥金尼地穴", GOSSIP_SENDER_MAIN, 1008);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "塞泰克大厅", GOSSIP_SENDER_MAIN, 1009);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "法力陵墓", GOSSIP_SENDER_MAIN, 1010);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "能源舰", GOSSIP_SENDER_MAIN, 1011);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "生态船", GOSSIP_SENDER_MAIN, 1012);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "禁魔监狱", GOSSIP_SENDER_MAIN, 1013);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "黑色沼泽", GOSSIP_SENDER_MAIN, 1014);
                break;
            
            // 副本 - 诺森德
            case 11:
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "乌特加德城堡", GOSSIP_SENDER_MAIN, 1101);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "魔枢", GOSSIP_SENDER_MAIN, 1102);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "艾卓-尼鲁布", GOSSIP_SENDER_MAIN, 1103);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "安卡赫特：古代王国", GOSSIP_SENDER_MAIN, 1104);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "达克萨隆要塞", GOSSIP_SENDER_MAIN, 1105);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "紫罗兰监狱", GOSSIP_SENDER_MAIN, 1106);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "古达克", GOSSIP_SENDER_MAIN, 1107);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "岩石大厅", GOSSIP_SENDER_MAIN, 1108);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "闪电大厅", GOSSIP_SENDER_MAIN, 1109);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "乌特加德之巅", GOSSIP_SENDER_MAIN, 1110);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "魔环", GOSSIP_SENDER_MAIN, 1111);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "净化斯坦索姆", GOSSIP_SENDER_MAIN, 1112);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "冠军的试炼", GOSSIP_SENDER_MAIN, 1113);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "灵魂熔炉", GOSSIP_SENDER_MAIN, 1114);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "萨隆矿坑", GOSSIP_SENDER_MAIN, 1115);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "映像大厅", GOSSIP_SENDER_MAIN, 1116);
                break;
            
            // 其他区域
            case 12:
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "GM岛", GOSSIP_SENDER_MAIN, 1201);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "深岩之洲", GOSSIP_SENDER_MAIN, 1202);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "海加尔山", GOSSIP_SENDER_MAIN, 1203);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "时光之穴", GOSSIP_SENDER_MAIN, 1204);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "翡翠梦境", GOSSIP_SENDER_MAIN, 1205);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "暗月岛", GOSSIP_SENDER_MAIN, 1206);
                break;
        }

        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<< 返回", GOSSIP_SENDER_MAIN, 0);
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, item->GetGUID());
    }

    void TeleportTo(Player* player, uint32 locationId)
    {
        switch (locationId)
        {
            // 联盟主城
            case 101: // 暴风城
                player->TeleportTo(0, -8835.76f, 490.084f, 109.799f, 0.0f);
                break;
            case 102: // 铁炉堡
                player->TeleportTo(0, -4821.13f, -1152.4f, 502.295f, 0.0f);
                break;
            case 103: // 达纳苏斯
                player->TeleportTo(1, 9978.11f, 2036.0f, 1328.06f, 0.0f);
                break;
            
            // 部落主城
            case 201: // 幽暗城
                player->TeleportTo(0, 1628.3f, 239.925f, 64.5006f, 0.0f);
                break;
            case 202: // 银月城
                player->TeleportTo(530, 9934.885742f, -7127.350098f, -169.862839f, 0.0f);
                break;
            case 351: // 奥格瑞玛
                player->TeleportTo(1, 1676.25f, -4313.45f, 61.7176f, 0.0f);
                break;
            case 352: // 雷霆崖
                player->TeleportTo(1, -1196.75f, 26.0777f, 177.033f, 0.0f);
                break;
            
            // 东部王国 - 联盟区域
            case 104: // 艾尔文森林
                player->TeleportTo(0, -9443.45f, 59.8944f, 56.0704f, 0.0f);
                break;
            case 105: // 西部荒野
                player->TeleportTo(0, -10510.0f, 1046.89f, 60.518f, 0.0f);
                break;
            case 106: // 赤脊山
                player->TeleportTo(0, -9277.857422f, -2285.332275f, 67.740242f, 0.0f);
                break;
            case 107: // 暮色森林
                player->TeleportTo(0, -10556.147461f, -1168.075073f, 27.752821f, 0.0f);
                break;
            case 108: // 荆棘谷
                player->TeleportTo(0, -11977.4f, 332.254f, 3.20626f, 0.0f);
                break;
            case 109: // 希尔斯布莱德丘陵
                player->TeleportTo(0, -821.604f, -544.654f, 15.0387f, 0.0f);
                break;
            case 110: // 奥特兰克山脉
                player->TeleportTo(0, 322.373138f, -1487.853882f, 43.720089f, 0.0f);
                break;
            case 111: // 西瘟疫之地
                player->TeleportTo(0, 953.8f, -1430.0f, 63.822098f, 0.0f);
                break;
            case 112: // 东瘟疫之地
                player->TeleportTo(0, 2278.364258f, -5311.157227f, 87.200989f, 0.0f);
                break;
            case 113: // 提瑞斯法林地
                player->TeleportTo(0, 2260.64f, 289.021f, 34.1291f, 0.0f);
                break;
            
            // 东部王国 - 部落区域
            case 203: // 永歌森林
                player->TeleportTo(530, 9499.94f, -7868.79f, 16.1281f, 530);
                break;
            case 204: // 幽魂之地
                player->TeleportTo(530, 7579.28f, -6822.69f, 86.5291f, 530);
                break;
            case 205: // 奎尔丹纳斯岛
                player->TeleportTo(530, 12915.85f, -6862.04f, 7.68f, 530);
                break;
            case 206: // 提瑞斯法林地
                player->TeleportTo(0, 2260.64f, 289.021f, 34.1291f, 0.0f);
                break;
            case 207: // 银松森林
                player->TeleportTo(0, 507.784f, 1611.33f, 124.921f, 0.0f);
                break;
            case 208: // 希尔斯布莱德丘陵
                player->TeleportTo(0, -28.1484f, -899.243f, 56.0704f, 0.0f);
                break;
            case 209: // 辛特兰
                player->TeleportTo(0, 326.992401f, -1963.878052f, 197.087585f, 0.0f);
                break;
            case 210: // 阿拉希高地
                player->TeleportTo(0, -1020.820496f, -3542.908203f, 56.442707f, 0.0f);
                break;
            case 211: // 荒芜之地
                player->TeleportTo(0, -7027.81f, -3330.11f, 241.51f, 0.0f);
                break;
            case 212: // 灼热峡谷
                player->TeleportTo(0, -6888.953125f, -1336.459961f, 239.923050f, 0.0f);
                break;
            case 213: // 燃烧平原
                player->TeleportTo(0, -7494.010254f, -2181.415039f, 165.573975f, 0.0f);
                break;
            
            // 卡利姆多 - 联盟区域
            case 301: // 达纳苏斯
                player->TeleportTo(1, 9978.11f, 2036.0f, 1328.06f, 0.0f);
                break;
            case 302: // 泰达希尔
                player->TeleportTo(1, 10455.7f, 798.455f, 1346.75f, 0.0f);
                break;
            case 303: // 黑海岸
                player->TeleportTo(1, 6441.729004f, 485.862885f, 7.691852f, 0.0f);
                break;
            case 304: // 灰谷
                player->TeleportTo(1, 2745.85f, -378.33f, 108.253f, 0.0f);
                break;
            case 305: // 石爪山脉
                player->TeleportTo(1, 968.077f, 1042.29f, 104.563f, 0.0f);
                break;
            case 306: // 凄凉之地
                player->TeleportTo(1, -147.011230f, 1231.578979f, 165.476013f, 0.0f);
                break;
            case 307: // 菲拉斯
                player->TeleportTo(1, -4369.68f, 242.294f, 25.4133f, 0.0f);
                break;
            case 308: // 羽月要塞
                player->TeleportTo(1, -4411.091309f, 3228.021484f, 12.129439f, 0.0f);
                break;
            case 309: // 塔纳利斯
                player->TeleportTo(1, -7124.131836f, -3818.932129f, 8.410748f, 0.0f);
                break;
            case 310: // 安戈洛环形山
                player->TeleportTo(1, -6186.573730f, -1106.830322f, -217.059799f, 0.0f);
                break;
            case 311: // 希利苏斯
                player->TeleportTo(1, -6810.2f, 841.704f, 49.8481f, 0.0f);
                break;
            case 312: // 冬泉谷
                player->TeleportTo(1, 6721.442383f, -4659.089355f, 720.892578f, 0.0f);
                break;
            
            // 卡利姆多 - 部落区域
            case 353: // 杜隆塔尔
                player->TeleportTo(1, 304.762f, -4734.97f, 9.30458f, 0.0f);
                break;
            case 354: // 贫瘠之地
                player->TeleportTo(1, -456.263f, -2652.7f, 95.615f, 0.0f);
                break;
            case 355: // 莫高雷
                player->TeleportTo(1, -2321.74f, -378.941f, -8.568934f, 0.0f);
                break;
            case 356: // 尘泥沼泽
                player->TeleportTo(1, -3129.38f, -2864.51f, 34.8711f, 0.0f);
                break;
            case 357: // 凄凉之地
                player->TeleportTo(1, -1770.37f, 3262.19f, 5.10852f, 0.0f);
                break;
            case 358: // 菲拉斯
                player->TeleportTo(1, -4369.68f, 242.294f, 25.4133f, 0.0f);
                break;
            case 359: // 塔纳利斯
                player->TeleportTo(1, -7124.131836f, -3818.932129f, 8.410748f, 0.0f);
                break;
            case 360: // 安戈洛环形山
                player->TeleportTo(1, -6186.573730f, -1106.830322f, -217.059799f, 0.0f);
                break;
            case 361: // 希利苏斯
                player->TeleportTo(1, -6810.2f, 841.704f, 49.8481f, 0.0f);
                break;
            case 362: // 冬泉谷
                player->TeleportTo(1, 6721.442383f, -4659.089355f, 720.892578f, 0.0f);
                break;
            
            // 外域 - 联盟区域
            case 401: // 荣耀堡
                player->TeleportTo(530, -679.361f, 2668.36f, 89.7899f, 0.0f);
                break;
            case 402: // 沙塔斯城
                player->TeleportTo(530, -1897.82f, 5768.27f, 131.414f, 0.0f);
                break;
            case 403: // 奥蕾莉亚要塞
                player->TeleportTo(530, -2580.94f, 3331.18f, -0.314187f, 0.0f);
                break;
            case 404: // 泰雷多尔
                player->TeleportTo(530, 280.384f, 6041.81f, 130.286f, 0.0f);
                break;
            case 405: // 希尔瓦纳
                player->TeleportTo(530, 2058.87f, 6851.6f, 172.596f, 0.0f);
                break;
            case 406: // 纳格兰
                player->TeleportTo(530, -1319.78f, 7213.66f, 33.6459f, 0.0f);
                break;
            case 407: // 虚空风暴
                player->TeleportTo(530, 3049.15f, 3686.12f, 142.387f, 0.0f);
                break;
            case 408: // 蛮锤要塞
                player->TeleportTo(530, -3959.63f, 2187.07f, 101.764f, 0.0f);
                break;
            
            // 外域 - 部落区域
            case 451: // 萨尔玛
                player->TeleportTo(530, 143.151f, 2673.19f, 85.676f, 0.0f);
                break;
            case 452: // 沙塔斯城
                player->TeleportTo(530, -1897.82f, 5768.27f, 131.414f, 0.0f);
                break;
            case 453: // 裂石堡
                player->TeleportTo(530, -2563.19f, 4426.77f, 39.4383f, 0.0f);
                break;
            case 454: // 萨布拉金
                player->TeleportTo(530, 261.398f, 7859.78f, 23.3885f, 0.0f);
                break;
            case 455: // 雷神要塞
                player->TeleportTo(530, 2382.8f, 6044.77f, 139.549f, 0.0f);
                break;
            case 456: // 纳格兰
                player->TeleportTo(530, -1256.63f, 7136.17f, 57.3484f, 0.0f);
                break;
            case 457: // 虚空风暴
                player->TeleportTo(530, 3049.15f, 3686.12f, 142.387f, 0.0f);
                break;
            case 458: // 影月村
                player->TeleportTo(530, -3061.65f, 2541.14f, 62.325f, 0.0f);
                break;
            
            // 诺森德 - 联盟区域
            case 501: // 无畏要塞
                player->TeleportTo(571, 2272.9799f, 5171.8198f, 11.3460f, 0.0f);
                break;
            case 502: // 瓦加德
                player->TeleportTo(571, 567.4149f, -5012.5800f, 11.6673f, 0.0f);
                break;
            case 503: // 暮冬要塞
                player->TeleportTo(571, 3713.0559f, -691.9813f, 215.5497f, 0.0f);
                break;
            case 504: // 琥珀松木营地
                player->TeleportTo(571, 3447.812f, -2754.3974f, 199.3689f, 0.0f);
                break;
            case 505: // 银色前沿
                player->TeleportTo(571, 5523.6801f, -2674.9699f, 304.1369f, 0.0f);
                break;
            case 506: // 奈辛瓦里营地
                player->TeleportTo(571, 5590.0297f, 5828.5600f, -68.1586f, 0.0f);
                break;
            case 507: // K3
                player->TeleportTo(571, 6188.9702f, -1056.5300f, 410.0060f, 0.0f);
                break;
            case 508: // 银色前线基地
                player->TeleportTo(571, 6162.6201f, -62.0920f, 388.3640f, 0.0f);
                break;
            case 509: // 达拉然
                player->TeleportTo(571, 5813.3701f, 453.4030f, 658.9340f, 0.0f);
                break;
            
            // 诺森德 - 部落区域
            case 601: // 战歌要塞
                player->TeleportTo(571, 2920.2900f, 6242.8500f, 208.8000f, 0.0f);
                break;
            case 602: // 复仇港
                player->TeleportTo(571, 1919.0300f, -6176.7202f, 24.6655f, 0.0f);
                break;
            case 603: // 阿格玛之锤
                player->TeleportTo(571, 3863.6298f, 1523.1099f, 90.3258f, 0.0f);
                break;
            case 604: // 征服堡
                player->TeleportTo(571, 3261.520f, -2265.4499f, 114.2809f, 0.0f);
                break;
            case 605: // 圣光据点
                player->TeleportTo(571, 5189.6699f, -2206.8500f, 239.3999f, 0.0f);
                break;
            case 606: // 奈辛瓦里营地
                player->TeleportTo(571, 5590.0297f, 5828.5600f, -68.1586f, 0.0f);
                break;
            case 607: // 格罗玛什坠毁点
                player->TeleportTo(571, 7857.2998f, -735.0200f, 1177.1500f, 0.0f);
                break;
            case 608: // 暗影拱顶
                player->TeleportTo(571, 8412.0634f, 2693.3571f, 655.0952f, 0.0f);
                break;
            case 609: // 达拉然
                player->TeleportTo(571, 5813.3701f, 453.4030f, 658.9340f, 0.0f);
                break;
            
            // 战场
            case 701: // 奥特兰克山谷
                player->TeleportTo(30, 617.276672f, -42.834068f, 42.289104f, 0.0f);
                break;
            case 702: // 战歌峡谷
                player->TeleportTo(489, 1458.6f, 1545.07f, 343.04f, 0.0f);
                break;
            case 703: // 阿拉希盆地
                player->TeleportTo(529, 1292.41f, 1288.80f, -13.64f, 0.0f);
                break;
            case 704: // 风暴之眼
                player->TeleportTo(566, 2174.23f, 1569.57f, 1159.959595f, 0.0f);
                break;
            case 705: // 远古海滩
                player->TeleportTo(607, 1637.28f, -106.279f, 30.0f, 0.0f);
                break;
            case 706: // 征服之岛
                player->TeleportTo(628, 748.0f, 635.0f, -12.0f, 0.0f);
                break;
            
            // 副本 - 东部王国
            case 801: // 死亡矿井
                player->TeleportTo(36, -16.40f, -383.07f, 61.78f, 0.0f);
                break;
            case 802: // 监狱
                player->TeleportTo(34, 49.821239f, 0.870144f, -16.713627f, 0.0f);
                break;
            case 803: // 血色修道院
                player->TeleportTo(189, 855.109985f, 1320.760010f, 18.670000f, 0.0f);
                break;
            case 804: // 通灵学院
                player->TeleportTo(289, 199.427017f, 126.463890f, 134.911682f, 0.0f);
                break;
            case 805: // 斯坦索姆
                player->TeleportTo(329, 3593.15f, -3646.56f, 138.50f, 0.0f);
                break;
            case 806: // 黑石深渊
                player->TeleportTo(230, 459.455994f, 27.085884f, -70.655228f, 0.0f);
                break;
            case 807: // 黑石塔
                player->TeleportTo(229, 79.99f, -233.34f, 52.02f, 0.0f);
                break;
            case 808: // 熔火之心
                player->TeleportTo(409, 1071.902954f, -488.489014f, -108.219124f, 0.0f);
                break;
            case 809: // 黑翼之巢
                player->TeleportTo(469, -7653.554688f, -1093.969116f, 404.183105f, 0.0f);
                break;
            
            // 副本 - 卡利姆多
            case 901: // 怒焰裂谷
                player->TeleportTo(389, 1.784903f, -14.368461f, -17.553291f, 0.0f);
                break;
            case 902: // 哀嚎洞穴
                player->TeleportTo(43, -160.004120f, 131.63653f, -74.079254f, 0.0f);
                break;
            case 903: // 剃刀沼泽
                player->TeleportTo(47, 1941.789551f, 1543.693604f, 81.661453f, 0.0f);
                break;
            case 904: // 剃刀高地
                player->TeleportTo(129, 2188.609863f, -2514.278564f, 81.024620f, 0.0f);
                break;
            case 905: // 黑暗深渊
                player->TeleportTo(48, -152.983551f, 106.329994f, -40.095310f, 0.0f);
                break;
            case 906: // 奥达曼
                player->TeleportTo(70, -228.192993f, 46.160198f, -46.018631f, 0.0f);
                break;
            case 907: // 玛拉顿
                player->TeleportTo(349, 1019.69f, -458.31f, -43.43f, 0.0f);
                break;
            case 908: // 祖尔法拉克
                player->TeleportTo(209, 1221.820557f, 840.745728f, 8.976474f, 0.0f);
                break;
            case 909: // 厄运之槌
                player->TeleportTo(429, 47.629997f, -155.270004f, -2.714379f, 0.0f);
                break;
            case 910: // 安其拉废墟
                player->TeleportTo(509, -8429.743164f, 1512.136475f, 31.907234f, 0.0f);
                break;
            case 911: // 安其拉神殿
                player->TeleportTo(531, -8231.330078f, 2010.599976f, 129.330505f, 0.0f);
                break;
            
            // 副本 - 外域
            case 1001: // 地狱火城墙
                player->TeleportTo(543, -1348.61f, 1651.06f, 68.8195f, 0.0f);
                break;
            case 1002: // 鲜血熔炉
                player->TeleportTo(542, -3.41257f, 2.00423f, -44.2242f, 0.0f);
                break;
            case 1003: // 破碎大厅
                player->TeleportTo(540, -0.509273f, 3.83735f, -13.1962f, 0.0f);
                break;
            case 1004: // 奴隶围栏
                player->TeleportTo(547, 0.0f, 0.0f, -1.09796f, 0.0f);
                break;
            case 1005: // 幽暗沼泽
                player->TeleportTo(546, 0.0f, 0.0f, -2.75242f, 0.0f);
                break;
            case 1006: // 蒸汽地窟
                player->TeleportTo(545, 0.0f, 0.0f, -4.19087f, 0.0f);
                break;
            case 1007: // 暗影迷宫
                player->TeleportTo(555, 0.0f, 0.0f, -1.12795f, 0.0f);
                break;
            case 1008: // 奥金尼地穴
                player->TeleportTo(558, 0.0f, 0.0f, 0.0f, 0.0f);
                break;
            case 1009: // 塞泰克大厅
                player->TeleportTo(556, 0.0f, 0.0f, 0.006213f, 0.0f);
                break;
            case 1010: // 法力陵墓
                player->TeleportTo(557, 0.013477f, 0.930826f, -0.954333f, 0.0f);
                break;
            case 1011: // 能源舰
                player->TeleportTo(554, 0.0f, 0.0f, -1.81282f, 0.0f);
                break;
            case 1012: // 生态船
                player->TeleportTo(553, 0.0f, 0.0f, -1.59128f, 0.0f);
                break;
            case 1013: // 禁魔监狱
                player->TeleportTo(552, 12.879066f, 0.525871f, -0.205504f, 0.0f);
                break;
            case 1014: // 黑色沼泽
                player->TeleportTo(269, -2033.498413f, 7120.973633f, 22.664389f, 0.0f);
                break;
            
            // 副本 - 诺森德
            case 1101: // 乌特加德城堡
                player->TeleportTo(574, 153.789f, -86.548f, 12.551f, 0.0f);
                break;
            case 1102: // 魔枢
                player->TeleportTo(576, 145.87f, -10.554f, -16.636f, 0.0f);
                break;
            case 1103: // 艾卓-尼鲁布
                player->TeleportTo(601, 413.314f, 795.968f, 831.351f, 0.0f);
                break;
            case 1104: // 安卡赫特：古代王国
                player->TeleportTo(619, 333.3510f, -1109.9399f, 69.7720f, 0.0f);
                break;
            case 1105: // 达克萨隆要塞
                player->TeleportTo(600, -517.343f, -487.976f, 11.01f, 0.0f);
                break;
            case 1106: // 紫罗兰监狱
                player->TeleportTo(608, 1808.8199f, 803.9299f, 44.3639f, 0.0f);
                break;
            case 1107: // 古达克
                player->TeleportTo(604, 1891.84f, 832.169f, 176.669f, 0.0f);
                break;
            case 1108: // 岩石大厅
                player->TeleportTo(599, 1153.24f, 806.164f, 195.937f, 0.0f);
                break;
            case 1109: // 闪电大厅
                player->TeleportTo(602, 1331.47f, 259.619f, 53.398f, 0.0f);
                break;
            case 1110: // 乌特加德之巅
                player->TeleportTo(575, 584.117f, -327.974f, 110.138f, 0.0f);
                break;
            case 1111: // 魔环
                player->TeleportTo(578, 1048.16f, 1108.3f, 361.07f, 0.0f);
                break;
            case 1112: // 净化斯坦索姆
                player->TeleportTo(595, 1431.1f, 556.92f, 36.69f, 0.0f);
                break;
            case 1113: // 冠军的试炼
                player->TeleportTo(650, 805.227f, 617.487f, 412.393f, 0.0f);
                break;
            case 1114: // 灵魂熔炉
                player->TeleportTo(632, 4922.86f, 217.42f, 243.03f, 0.0f);
                break;
            case 1115: // 萨隆矿坑
                player->TeleportTo(658, 435.68f, 212.41f, 528.71f, 0.0f);
                break;
            case 1116: // 映像大厅
                player->TeleportTo(668, 5239.46f, 1932.39f, 707.695f, 0.0f);
                break;
            
            // 其他区域
            case 1201: // GM岛
                player->TeleportTo(1, 16222.1f, 16252.1f, 12.5872f, 0.0f);
                break;
            case 1202: // 深岩之洲
                player->TeleportTo(646, 996.22f, 503.69f, -49.22f, 0.0f);
                break;
            case 1203: // 海加尔山
                player->TeleportTo(1, 4674.88f, -3638.37f, 965.264f, 0.0f);
                break;
            case 1204: // 时光之穴
                player->TeleportTo(1, -8195.938477f, -4500.128418f, 8.608192f, 0.0f);
                break;
            case 1205: // 翡翠梦境
                player->TeleportTo(169, 3105.41f, 3096.78f, 27.0032f, 0.0f);
                break;
            case 1206: // 暗月岛
                player->TeleportTo(974, -4073.03f, 6356.08f, 13.05f, 0.0f);
                break;
            
            default:
                break;
        }
        
        CloseGossipMenuFor(player);
    }

public:
    void OnGossipSelect(Player* player, Item* item, uint32 /*sender*/, uint32 action) override
    {
        if (action == 0) {
            ShowMainMenu(player, item);
            //return true;
        }
        
        // 主大陆选择
        if (action <= 100) {
            ShowContinentMenu(player, item, action);
        }
        // 具体传送点
        else {
            TeleportTo(player, action);
        }
        
        //return true;
    }
};

void AddSC_TeleportBook()
{
    new TeleportBook();
}
