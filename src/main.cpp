#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <random>
#include <iomanip>

using namespace geode::prelude;

enum ItemType {
    Cube = 0,
    Ship = 1,
    Ball = 2,
    Ufo = 3,
    Wave = 4,
    Robot = 5,
    Spider = 6,
    Swing = 7,
    Jetpack = 8,
    DeathEffect = 98,
    Special = 99,
    Color1 = 100,
    Color2 = 101
};

int getMaxIconForType(ItemType type) {
    switch (type) {
        case Cube: return 484;
        case Ship: return 169;
        case Ball: return 118;
        case Ufo: return 149;
        case Wave: return 96;
        case Robot: return 68;
        case Spider: return 69;
        case Swing: return 43;
        case Jetpack: return 5;
        case DeathEffect: return 20;
        case Special: return 7;
        case Color1: return 107;
        case Color2: return 107;
        default: return 1;
    }
}

// oh god

CCDictionary* m_cubesRarity;
CCDictionary* m_shipsRarity;
CCDictionary* m_ballsRarity;
CCDictionary* m_ufosRarity;
CCDictionary* m_wavesRarity;
CCDictionary* m_robotsRarity;
CCDictionary* m_spidersRarity;
CCDictionary* m_swingsRarity;
CCDictionary* m_jetpacksRarity;
CCDictionary* m_specialsRarity;
CCDictionary* m_effectsRarity;
CCDictionary* m_color1Rarity;
CCDictionary* m_color2Rarity;

int getRarity(int id, ItemType type) {
    switch (type) {
        case Cube: if (auto r = dynamic_cast<CCString*>(m_cubesRarity->objectForKey(id))) return std::atoi(r->getCString());
        case Ship: if (auto r = dynamic_cast<CCString*>(m_shipsRarity->objectForKey(id))) return std::atoi(r->getCString());
        case Ball: if (auto r = dynamic_cast<CCString*>(m_ballsRarity->objectForKey(id))) return std::atoi(r->getCString());
        case Ufo: if (auto r = dynamic_cast<CCString*>(m_ufosRarity->objectForKey(id))) return std::atoi(r->getCString());
        case Wave: if (auto r = dynamic_cast<CCString*>(m_wavesRarity->objectForKey(id))) return std::atoi(r->getCString());
        case Robot: if (auto r = dynamic_cast<CCString*>(m_robotsRarity->objectForKey(id))) return std::atoi(r->getCString());
        case Spider: if (auto r = dynamic_cast<CCString*>(m_spidersRarity->objectForKey(id))) return std::atoi(r->getCString());
        case Swing: if (auto r = dynamic_cast<CCString*>(m_swingsRarity->objectForKey(id))) return std::atoi(r->getCString());
        case Jetpack: if (auto r = dynamic_cast<CCString*>(m_jetpacksRarity->objectForKey(id))) return std::atoi(r->getCString());
        case Special: if (auto r = dynamic_cast<CCString*>(m_specialsRarity->objectForKey(id))) return std::atoi(r->getCString());
        case DeathEffect: if (auto r = dynamic_cast<CCString*>(m_effectsRarity->objectForKey(id))) return std::atoi(r->getCString());
        case Color1: if (auto r = dynamic_cast<CCString*>(m_color1Rarity->objectForKey(id))) return std::atoi(r->getCString());
        case Color2: if (auto r = dynamic_cast<CCString*>(m_color2Rarity->objectForKey(id))) return std::atoi(r->getCString());
        default: return 0;
    }
}

int priceFromRarity(int rarity) {
    switch (rarity) {
    case 1: return 1000;
    case 2: return 3000;
    case 3: return 5000;
    case 4: return 0;
    default: return 500;
    }
}

bool oneTime = true;
void defineIconsRarity() {
    if (oneTime) {
        m_cubesRarity = CCDictionary::create();
        m_cubesRarity->retain();
        m_shipsRarity = CCDictionary::create();
        m_shipsRarity->retain();
        m_ballsRarity = CCDictionary::create();
        m_ballsRarity->retain();
        m_ufosRarity = CCDictionary::create();
        m_ufosRarity->retain();
        m_wavesRarity = CCDictionary::create();
        m_wavesRarity->retain();
        m_robotsRarity = CCDictionary::create();
        m_robotsRarity->retain();
        m_spidersRarity = CCDictionary::create();
        m_spidersRarity->retain();
        m_swingsRarity = CCDictionary::create();
        m_swingsRarity->retain();
        m_jetpacksRarity = CCDictionary::create();
        m_jetpacksRarity->retain();
        m_specialsRarity = CCDictionary::create();
        m_specialsRarity->retain();
        m_effectsRarity = CCDictionary::create();
        m_effectsRarity->retain();
        m_color1Rarity = CCDictionary::create();
        m_color1Rarity->retain();
        m_color2Rarity = CCDictionary::create();
        m_color2Rarity->retain();

        auto s = GameStatsManager::sharedState();

        for (int i = 5; i <= getMaxIconForType(Cube); i++) {
            if (i > 4 && i <= 142) m_cubesRarity->setObject(CCString::create("0"), i);
            else if (i > 142) m_cubesRarity->setObject(CCString::create("2"), i);
            else m_cubesRarity->setObject(CCString::create("1"), i);

            s->addStoreItem(2000 + i, 9999, 1, priceFromRarity(getRarity(i, Cube)), (ShopType)10);
        }
        for (int i = 2; i <= getMaxIconForType(Ship); i++) {
            if (i > 1 && i <= 21) m_shipsRarity->setObject(CCString::create("0"), i);
            else if (i > 51) m_shipsRarity->setObject(CCString::create("2"), i);
            else m_shipsRarity->setObject(CCString::create("1"), i);

            s->addStoreItem(4000 + i, 9999, 1, priceFromRarity(getRarity(i, Ship)), (ShopType)10);
        }
        for (int i = 2; i <= getMaxIconForType(Ball); i++) {
            if (i > 1 && i <= 22) m_ballsRarity->setObject(CCString::create("0"), i);
            else if (i > 43) m_ballsRarity->setObject(CCString::create("2"), i);
            else m_ballsRarity->setObject(CCString::create("1"), i);

            s->addStoreItem(6000 + i, 9999, 1, priceFromRarity(getRarity(i, Ball)), (ShopType)10);
        }
        for (int i = 2; i <= getMaxIconForType(Ufo); i++) {
            if (i > 1 && i <= 20) m_ufosRarity->setObject(CCString::create("0"), i);
            else if (i > 35) m_ufosRarity->setObject(CCString::create("2"), i);
            else m_ufosRarity->setObject(CCString::create("1"), i);

            s->addStoreItem(8000 + i, 9999, 1, priceFromRarity(getRarity(i, Ufo)), (ShopType)10);
        }
        for (int i = 2; i <= getMaxIconForType(Wave); i++) {
            if (i > 1 && i <= 23) m_wavesRarity->setObject(CCString::create("0"), i);
            else if (i > 35) m_wavesRarity->setObject(CCString::create("2"), i);
            else m_wavesRarity->setObject(CCString::create("1"), i);

            s->addStoreItem(10000 + i, 9999, 1, priceFromRarity(getRarity(i, Wave)), (ShopType)10);
        }
        for (int i = 2; i <= getMaxIconForType(Robot); i++) {
            if (i > 1 && i <= 6) m_robotsRarity->setObject(CCString::create("0"), i);
            else if (i > 26) m_robotsRarity->setObject(CCString::create("2"), i);
            else m_robotsRarity->setObject(CCString::create("1"), i);

            s->addStoreItem(12000 + i, 9999, 1, priceFromRarity(getRarity(i, Robot)), (ShopType)10);
        }
        for (int i = 2; i <= getMaxIconForType(Spider); i++) {
            if (i > 1 && i <= 4) m_spidersRarity->setObject(CCString::create("0"), i);
            else if (i > 17) m_spidersRarity->setObject(CCString::create("2"), i);
            else m_spidersRarity->setObject(CCString::create("1"), i);

            s->addStoreItem(14000 + i, 9999, 1, priceFromRarity(getRarity(i, Spider)), (ShopType)10);
        }
        for (int i = 2; i <= getMaxIconForType(Swing); i++) {
            m_swingsRarity->setObject(CCString::create("2"), i);

            s->addStoreItem(16000 + i, 9999, 1, priceFromRarity(getRarity(i, Swing)), (ShopType)10);
        }
        for (int i = 2; i <= getMaxIconForType(Jetpack); i++) {
            m_jetpacksRarity->setObject(CCString::create("1"), i);

            s->addStoreItem(18000 + i, 9999, 1, priceFromRarity(getRarity(i, Jetpack)), (ShopType)10);
        }
        for (int i = 2; i <= getMaxIconForType(Special); i++) {
            if (i == 2) m_specialsRarity->setObject(CCString::create("3"), i);
            else if (i == 5 || i == 6) m_specialsRarity->setObject(CCString::create("1"), i);
            else m_specialsRarity->setObject(CCString::create("0"), i);

            s->addStoreItem(198000 + i, 9999, 1, priceFromRarity(getRarity(i, Special)), (ShopType)10);
        }
        for (int i = 2; i <= getMaxIconForType(DeathEffect); i++) {
            m_effectsRarity->setObject(CCString::create("1"), i);

            s->addStoreItem(196000 + i, 9999, 1, priceFromRarity(getRarity(i, DeathEffect)), (ShopType)10);
        }
        for (int i = 0; i <= getMaxIconForType(Color1); i++) {
            m_color1Rarity->setObject(CCString::create("0"), i);
            m_color2Rarity->setObject(CCString::create("0"), i);

            // same value for color
            s->addStoreItem(200000 + i, 9999, 1, priceFromRarity(getRarity(i, Color1)), (ShopType)10);
            s->addStoreItem(202000 + i, 9999, 1, priceFromRarity(getRarity(i, Color2)), (ShopType)10);
        }

        oneTime = false;
    }
}

const char* nameFromRarity(int rarity) {
    switch (rarity) {
    case 1: return "Rare";
    case 2: return "Unusual";
    case 3: return "Legendary";
    case 4: return "Free";
    default: return "Common";
    }
}
ccColor3B colorFromRarity(int rarity) {
    switch (rarity) {
    case 1: return { 194, 236, 165 }; // raro
    case 2: return { 168, 77, 87 }; // unusual
    case 3: return { 220, 216, 116 }; // legendario
    case 4: return { 77, 225, 255 }; // gratis
    default: return { 178, 182, 210 }; // comun
    }
}

CCArray* splitToCCArray(std::string text, char letra) {
    CCArray* arr = CCArray::create();
    std::istringstream string_stream(text);
    std::string segment;

    while (std::getline(string_stream, segment, letra)) {
        arr->addObject(CCString::create(segment.c_str()));
    }

    return arr;
}


CCNode* nodeFromItemType(ItemType tipo, int id) {
    switch (tipo) {
        case DeathEffect:
            if (auto spr = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("explosionIcon_%02d_001.png", id)->getCString()))
                return spr;
            else
                return CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png");
        case Special:
            if (auto spr = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("player_special_%02d_001.png", id)->getCString()))
                return spr;
            else
                return CCSprite::createWithSpriteFrameName("GJ_newBtn_001.png");
        case Color1:
        case Color2:
            auto bg = CCSprite::createWithSpriteFrameName("player_special_01_001.png");
            bg->setColor(GameManager::sharedState()->colorForIdx(id));
            auto _id = CCLabelBMFont::create(CCString::createWithFormat("%i", tipo - 99)->getCString(), "bigFont.fnt");
            _id->setPosition(bg->getContentSize() / 2);
            _id->setScale(.5f);
            if (bg->getColor() != ccColor3B(0,0,0))
                _id->setColor(bg->getColor());
            bg->addChild(_id);
            return bg;
    }
    auto icon = SimplePlayer::create(id);
    icon->updatePlayerFrame(id, (IconType)tipo);
    if (tipo == Robot)
        icon->m_robotSprite->runAnimation("idle01");
    else if (tipo == Spider)
        icon->m_spiderSprite->runAnimation("idle01");

    icon->setColor({ 175, 175, 175 });
    return icon;
}

const char* getNameFromItemType(ItemType tipo) {
    switch (tipo) {
        case Cube: return "Cube";
        case Ship: return "Ship";
        case Ball: return "Ball";
        case Ufo: return "Ufo";
        case Wave: return "Wave";
        case Robot: return "Robot";
        case Spider: return "Spider";
        case Swing: return "Swing";
        case Jetpack: return "Jetpack";
        case DeathEffect: return "Death Effect";
        case Special: return "Special";
        case Color1: return "Main Color";
        case Color2: return "Second Color";
        default: return "?";
    }
}

bool m_bajado = false;
class MenuSelector : public CCLayer {
    int m_nToggled;
public:
    bool init() {
        this->setID("menu-selector"_spr);
        auto size = CCDirector::sharedDirector()->getWinSize();

        auto b = CCLayerColor::create({ 0, 0, 0, 150 });
        b->setContentSize({ size.width, 40 });
        b->setPosition({ size.width / 2 - b->getContentSize().width / 2, size.height - b->getContentSize().height + 5 });
        this->addChild(b);

        auto botones = CCMenu::create();
        for (int i = 0; i < 2; i++) {
            auto spr = ButtonSprite::create(this->getButtonName(i), 50, 0, "bigFont.fnt", "GJ_button_02.png", 25, 0.5);
            auto spr2 = ButtonSprite::create(this->getButtonName(i), 50, 0, "bigFont.fnt", "GJ_button_04.png", 25, 0.5);

            auto tog = CCMenuItemToggler::create(spr2, spr, this, menu_selector(MenuSelector::onAccion));
            tog->setTag(i);
            tog->setClickable(false);

            if (i == m_nToggled) tog->toggle(true);

            botones->addChild(tog);
        }
        botones->alignItemsHorizontallyWithPadding(10);
        botones->setPosition({ size.width / 2, size.height - 17 });
        this->addChild(botones, 1);

        if (m_nToggled == 0) {
            this->setZOrder(10);
            this->setPositionY(!m_bajado ? 35.0f : 0);

            auto menu = CCMenu::create();
            menu->setPosition({0,0});

            auto s = CCSprite::createWithSpriteFrameName("GJ_arrow_02_001.png");
            s->setScale(.7f);
            s->setRotation(!m_bajado ? -90 : 90);

            auto btn = CCMenuItemSpriteExtra::create(s, this, menu_selector(MenuSelector::onBajar));
            btn->setPosition({ size.width / 2, !m_bajado ? size.height - 10 - 2.5f - getPositionY() : size.height - 45 - 2.5f - getPositionY() });
            menu->addChild(btn);
            this->addChild(menu);
        }

        return true;
    }
    void onBajar(CCObject* s) {
        auto size = CCDirector::sharedDirector()->getWinSize();

        auto b = reinterpret_cast<CCMenuItemSpriteExtra*>(s);

        b->stopAllActions();
        b->getNormalImage()->stopAllActions();
        this->stopAllActions();

        if (!m_bajado) {
            this->runAction(CCEaseInOut::create(CCMoveTo::create(0.5f, { 0, 0 }), 2.0f));
            b->runAction(CCEaseInOut::create(CCMoveTo::create(0.5f, { size.width / 2, size.height - 45 - 2.5f }), 2.0f));
            b->getNormalImage()->runAction(CCEaseInOut::create(CCRotateTo::create(0.5f, 90), 2.0f));
        }
        else {
            this->runAction(CCEaseInOut::create(CCMoveTo::create(0.5f, { 0, 35 }), 2.0f));
            b->runAction(CCEaseInOut::create(CCMoveTo::create(0.5f, { size.width / 2, size.height - 10 - 2.5f - 35.0f }), 2.0f));
            b->getNormalImage()->runAction(CCEaseInOut::create(CCRotateTo::create(0.5f, -90), 2.0f));

        }

        m_bajado = !m_bajado;
    }
    void onAccion(CCObject* a);

    const char* getButtonName(int id) {
        switch (id) {
        case 1: return "Daily shop";
        default: return "Main menu";
        }
    }
    static MenuSelector* create(int toggled) {
        auto r = new MenuSelector;
        r->m_nToggled = toggled;
        if (r && r->init()) r->autorelease();
        else CC_SAFE_DELETE(r);
        return r;
    }
};

CCLabelBMFont* m_moneyLabel;
int saveTime = 0;

class ConfirmarCompra : public FLAlertLayer {
    CCArray* info;
    ItemType itemTipo;
    int itemID = 0;
    int price;
    CCNode* m_item;
    CCMenu* menu;
    CCMenu* menu3;
    CCLayer* iconsLayer;
    CCSprite* shadow;
public:
    bool init() {
        if (!FLAlertLayer::init(150)) return false;

        this->setTouchEnabled(true);
        this->setKeypadEnabled(true);

        auto size = CCDirector::sharedDirector()->getWinSize();

        m_mainLayer = CCLayer::create();

        auto bg = extension::CCScale9Sprite::create("GJ_square02.png");
        bg->setContentSize({ 360, 240 });
        bg->setPosition({ size.width / 2, size.height / 2 });
        m_mainLayer->addChild(bg, -1);

        itemTipo = (ItemType)info->stringAtIndex(4)->intValue();
        itemID = info->stringAtIndex(1)->intValue();

        bool comprado = false;
        if (itemTipo > 99) {
            comprado = GameManager::sharedState()->isColorUnlocked(itemID, (UnlockType)(itemTipo - 98));
        }
        else {
            comprado = GameManager::sharedState()->isIconUnlocked(itemID, (IconType)itemTipo);
        }

        auto titulo = CCLabelBMFont::create(comprado ? "Item" : "Confirm purchase", "bigFont.fnt");
        titulo->limitLabelWidth(200, 0.7f, 0);
        titulo->setPosition({ bg->getPositionX(), bg->getPositionY() + bg->getContentSize().height / 2 - 18 });
        m_mainLayer->addChild(titulo);

        auto bgI = extension::CCScale9Sprite::create("DS_itemBG.png"_spr);
        bgI->setContentSize({ 220, 100 });
        bgI->setColor(colorFromRarity(info->stringAtIndex(2)->intValue()));
        bgI->setPosition({ size.width / 2, size.height / 2 - 10 });
        m_mainLayer->addChild(bgI, -1);

        auto itemName = CCLabelBMFont::create(info->stringAtIndex(0)->getCString(), "bigFont.fnt");
        itemName->limitLabelWidth(bgI->getContentSize().width - 10, 0.6f, 0);
        itemName->setPosition({ bg->getPositionX(), bg->getPositionY() + 27 });
        m_mainLayer->addChild(itemName);

        menu = CCMenu::create();

        if (itemTipo == Robot || itemTipo == Spider) {
            float m_posY = 0, m_posX = 0;
            for (int i = 0; i < 6; i++) {
                auto button = CCMenuItemToggler::create(this->getSprite(i, false), this->getSprite(i, true), this, menu_selector(ConfirmarCompra::onToggle));
                button->setTag(i);
                button->setPosition({ -10 + m_posX, 0 - m_posY });
                button->setClickable(false);
                if (i == 0) button->toggle(true);

                m_posX += 30;
                if ((i + 1) % 2 == 0) {
                    m_posY += 30;
                    m_posX = 0;
                }

                menu->addChild(button);
            }
            menu->setPosition({ menu->getPositionX() - bg->getContentSize().width / 2 + 32, menu->getPositionY() + 22 });
        }
        else {
            if (itemTipo == DeathEffect) {
                auto spr = CCSprite::createWithSpriteFrameName("GJ_playBtn2_001.png");
                spr->setScale(.49f);
                auto spr2 = CCSprite::createWithSpriteFrameName("GJ_stopEditorBtn_001.png");
                auto button = CCMenuItemToggler::create(spr, spr2, this, menu_selector(ConfirmarCompra::onPreview));
                menu->addChild(button);
            }
            else if (itemTipo == Color1 || itemTipo == Color2) {
                iconsLayer = CCLayer::create();
                iconsLayer->setVisible(false);

                auto gm = GameManager::sharedState();
                float padX = 0, padY = 0, pad = 40;
                for (int i = 0; i < 9; i++) {
                    auto player = SimplePlayer::create(0);
                    player->setScale(.8f);
                    player->updatePlayerFrame(this->getPlayerIcon(i), (IconType)i);
                    player->setPosition({ bgI->getPositionX() - (pad * 2) + padX, bgI->getPositionY() + 5 - padY});
                    player->setColor(itemTipo == Color1 ? gm->colorForIdx(itemID) : gm->colorForIdx(gm->getPlayerColor()));
                    player->setSecondColor(itemTipo == Color2 ? gm->colorForIdx(itemID) : gm->colorForIdx(gm->getPlayerColor2()));
                    if (gm->getPlayerGlow())
                        player->setGlowOutline(itemTipo == Color2 ? gm->colorForIdx(itemID) : gm->colorForIdx(gm->getPlayerColor2()));
                    
                    padX += pad;
                    if ((i + 1) % 5 == 0) {
                        padX = pad / 2;
                        padY += 35;
                    }

                    iconsLayer->addChild(player);
                }
                m_mainLayer->addChild(iconsLayer);

                auto spr = CCSprite::create("GJ_button_01.png");
                auto spr2 = CCSprite::create("GJ_button_02.png");

                auto icon = CCSprite::createWithSpriteFrameName("particle_17_001.png");
                icon->setPosition(spr->getContentSize() / 2);
                icon->setScale(1.6f);
                spr->addChild(icon);
                spr2->addChild(icon);

                spr->setScale(.9f);
                spr2->setScale(spr->getScale());

                auto button = CCMenuItemToggler::create(spr, spr2, this, menu_selector(ConfirmarCompra::onPreview));
                menu->addChild(button);
            }
            menu->setPosition({ menu->getPositionX() + bg->getContentSize().width / 2 - 35, menu->getPositionY() - 10 });
        }

        menu->setTouchPriority(-504);
        m_mainLayer->addChild(menu);

        m_item = nodeFromItemType(itemTipo, itemID);
        m_item->setScale(1.4f);
        m_item->setPosition({ bgI->getPositionX(), bgI->getPositionY() - 10 });
        m_mainLayer->addChild(m_item);
        
        shadow = CCSprite::createWithSpriteFrameName("chest_shadow_001.png");
        shadow->setPosition({ m_item->getPositionX(), m_item->getPositionY() - 20 });
        shadow->setScale(.575f);
        shadow->setOpacity(90);
        m_mainLayer->addChild(shadow, -1);

        price = info->stringAtIndex(3)->intValue();

        if (comprado) {
            auto desc = TextArea::create(CCString::createWithFormat("This <cg>%s</c> is priced at <cy>%i</c> <cl>mana orbs</c>\n<co>(Owned)</c>", getNameFromItemType(itemTipo), price)->getCString(), "chatFont.fnt",  1, 300, { 0.5f, 0.5f }, 20, false);
            desc->setPosition({ bg->getPositionX(), bg->getPositionY() + 66 });
            desc->setScale(.8f);
            m_mainLayer->addChild(desc);
        }
        else {
            auto orbs = CCSprite::createWithSpriteFrameName("currencyOrbIcon_001.png");
            orbs->setScale(.8f);
            orbs->setPosition({ bgI->getPositionX() - bgI->getContentSize().width / 2 + 15 , bgI->getPositionY() - bgI->getContentSize().height / 2 + 15 });
            m_mainLayer->addChild(orbs);

            /*
            auto particle = CCParticleSystemQuad::create("keyEffect.plist", false);
            particle->setScale(.55f);
            particle->setPosition(orbs->getPosition());
            m_mainLayer->addChild(particle, -1);*/

            auto precio = CCLabelBMFont::create(CCString::createWithFormat("%i", price)->getCString(), "bigFont.fnt");
            precio->setAnchorPoint({ 0, 0.5f });
            precio->limitLabelWidth(100, .4f, 0);
            precio->setPosition({ orbs->getPositionX() + 12, orbs->getPositionY() + 1 });
            m_mainLayer->addChild(precio);

            auto desc = TextArea::create(CCString::createWithFormat("Are you sure you want to buy this <cg>%s</c> for <cy>%i</c> <cl>mana orbs</c>?\n<cr>(This action is unreversible)</c>", getNameFromItemType(itemTipo), price)->getCString(), "chatFont.fnt",  1, 300, { 0.5f, 0.5f }, 20, false);
            desc->setPosition({ bg->getPositionX(), bg->getPositionY() + 66 });
            desc->setScale(.7f);
            m_mainLayer->addChild(desc);
        }

        menu3 = CCMenu::create();

        if (comprado) {
            auto okBtn = CCMenuItemSpriteExtra::create(ButtonSprite::create("OK", 70, false, "goldFont.fnt", "GJ_button_01.png", 0.0f, 1), this, menu_selector(ConfirmarCompra::onClose));
            menu3->addChild(okBtn);
        }
        else {
            auto cancelBtn = CCMenuItemSpriteExtra::create(ButtonSprite::create("Cancel", 70, false, "goldFont.fnt", "GJ_button_06.png", 0.0f, 1), this, menu_selector(ConfirmarCompra::onClose));
            menu3->addChild(cancelBtn);

            auto submitBtn = CCMenuItemSpriteExtra::create(ButtonSprite::create("Buy!", 70, false, "goldFont.fnt", "GJ_button_01.png", 0.0f, 1), this, menu_selector(ConfirmarCompra::onBuy));
            menu3->addChild(submitBtn);
        }
        menu3->setPosition({ bg->getPositionX(), bg->getPositionY() - bg->getContentSize().height / 2 + 25 });
        menu3->alignItemsHorizontallyWithPadding(15);
        menu3->setTouchPriority(-504);

        m_mainLayer->addChild(menu3);
        this->addChild(m_mainLayer);
        return true;
    }
    int getPlayerIcon(int id) {
        auto gm = GameManager::sharedState();
        switch (id) {
            case 1: return gm->getPlayerShip();
            case 2: return gm->getPlayerBall();
            case 3: return gm->getPlayerBird();
            case 4: return gm->getPlayerDart();
            case 5: return gm->getPlayerRobot();
            case 6: return gm->getPlayerSpider();
            case 7: return gm->getPlayerSwing();
            case 8: return gm->getPlayerJetpack();
            default: return gm->getPlayerFrame();
        }
    }
    bool m_preview = false;
    void onPreview(CCObject*) {
        if (itemTipo == DeathEffect) {
            CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(CCString::createWithFormat("PlayerExplosion_%02d.plist", itemID - 1)->getCString(), CCString::createWithFormat("PlayerExplosion_%02d.png", itemID - 1)->getCString());
            
            auto spr = reinterpret_cast<CCSprite*>(m_item);
            if (!m_preview) {
                auto arr = new CCArray;
                float spriteSize = 0;
                for (int i = 1; i < 100; i++) {
                    auto formato = CCString::createWithFormat("playerExplosion_%02d_%03d.png", itemID - 1, i);
                    if (auto sprite = CCSprite::createWithSpriteFrameName(formato->getCString())) {
                        if (spriteSize < sprite->getContentSize().width) spriteSize = sprite->getContentSize().width;
                    }
                    else break;

                    arr->addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(formato->getCString()));
                }

                spr->setScale(75.0f / spriteSize);
                spr->runAction(CCRepeatForever::create(CCAnimate::create(CCAnimation::createWithSpriteFrames(arr, 0.05))));
            }
            else {
                const char* texture = CCString::createWithFormat("explosionIcon_%02d_001.png", itemID)->getCString();
                if (CCSprite::createWithSpriteFrameName(texture)) {
                    spr->stopAllActions();
                    spr->createWithSpriteFrameName(texture);
                    spr->initWithSpriteFrameName(texture);
                    spr->setScale(1.5f);
                }
            }
        }
        else {
            if (!m_preview) {
                m_item->setVisible(false);
                shadow->setVisible(false);
                iconsLayer->setVisible(true);
            }
            else {
                m_item->setVisible(true);
                shadow->setVisible(true);
                iconsLayer->setVisible(false);
            }
        }
        m_preview = !m_preview;
    }
    CCSprite* getSprite(int id, bool activated) {
        CCSprite* spr;
        if (itemTipo == Spider) {
            switch (id) {
                case 1:
                    spr = CCSprite::create("DS_spider_walk.png"_spr);
                    break;
                case 2:
                    spr = CCSprite::create("DS_spider_run.png"_spr);
                    break;
                case 3:
                    spr = CCSprite::createWithSpriteFrameName("gjItem_20_001.png");
                    break;
                case 4:
                    spr = CCSprite::create("DS_spider_jump.png"_spr);
                    break;
                case 5:
                    spr = CCSprite::create("DS_spider_fall.png"_spr);
                    break;
                default:
                    spr = CCSprite::create("DS_spider_idle.png"_spr);
                    break;
            }
        }
        else {
            switch (id) {
                case 1:
                    spr = CCSprite::create("DS_robot_run.png"_spr);
                    break;
                case 2:
                    spr = CCSprite::create("DS_robot_run2.png"_spr);
                    break;
                case 3:
                    spr = CCSprite::create("DS_robot_run3.png"_spr);
                    break;
                case 4:
                    spr = CCSprite::create("DS_robot_jump.png"_spr);
                    break;
                case 5:
                    spr = CCSprite::create("DS_robot_fall.png"_spr);
                    break;
                default:
                    spr = CCSprite::create("DS_robot_idle.png"_spr);
                    break;
            }
        }

        spr->setScale(.9f);
        if (!activated) spr->setColor({125,125,125});
        return spr;
    }
    void onToggle(CCObject* s) {
        auto btn = reinterpret_cast<CCMenuItemToggler*>(s);
        int tag = btn->getTag();

        for (int i = 0; i < menu->getChildrenCount(); i++) {
            reinterpret_cast<CCMenuItemToggler*>(menu->getChildren()->objectAtIndex(i))->toggle(false);
        }

        btn->toggle(true);
        auto p = reinterpret_cast<SimplePlayer*>(m_item);

        this->stopAllActions();

        if (itemTipo == Spider) {
            const char* anim = "idle01";
            switch (tag) { 
            case 1:
                anim = "walk";
                break;
            case 2:
                anim = "run";
                break;
            case 3:
                anim = "run2";
                break;
            case 4:
                anim = "jump";
                break;
            case 5:
                anim = "fall_loop";
                break;
            }
            
            p->m_spiderSprite->runAnimation(anim);
        }
        else {
            const char* anim = "idle01";
            switch (tag) { 
            case 1:
                anim = "run";
                break;
            case 2:
                anim = "run2";
                break;
            case 3:
                anim = "run3";
                break;
            case 4:
                anim = "jump_start";
                this->nextAnimation("jump_loop");
                break;
            case 5:
                anim = "fall_start";
                this->nextAnimation("fall_loop");
                break;
            }
            
            p->m_robotSprite->runAnimation(anim);
        }
    }
    
    void nextAnimation(const char* animation) {
        runAction(CCSequence::createWithTwoActions(CCDelayTime::create(0.15f), CCCallFuncO::create(this, callfuncO_selector(ConfirmarCompra::nextAnimation2), CCString::create(animation))));
    }
    void nextAnimation2(CCObject* a) {
        auto anim = reinterpret_cast<CCString*>(a)->getCString();
        if (itemTipo == Spider) {
            reinterpret_cast<SimplePlayer*>(m_item)->m_spiderSprite->runAnimation(anim);
        }
        else {
            reinterpret_cast<SimplePlayer*>(m_item)->m_robotSprite->runAnimation(anim);
        }
    }
    void onBuy(CCObject*) {
        auto gst = GameStatsManager::sharedState();
        if (gst->getStat("14") - price >= 0) {
            if (itemTipo > 99) {
                GameManager::sharedState()->unlockColor(itemID, (UnlockType)(itemTipo - 98));
            }
            else {
                GameManager::sharedState()->unlockIcon(itemID, (IconType)itemTipo);
            }

            if (itemTipo > 0) {
                gst->purchaseItem(2000 + (2000 * itemTipo) + itemID);
            }
            else {
                gst->purchaseItem(2000 + itemID);
            }

            m_moneyLabel->setString(CCString::createWithFormat("%i", gst->getStat("14"))->getCString());
            m_moneyLabel->limitLabelWidth(70, .4f, 0);

            saveTime = 0;
            
            FMODAudioEngine::sharedEngine()->playEffect("gold02.ogg");
        }
        else
            FLAlertLayer::create("Error", "You dont have sufficient <cl>mana orbs</c>", "OK")->show();

        this->onClose(nullptr);
    }
    void keyBackClicked() {
        this->onClose(nullptr);
    }
    void onClose(CCObject*) {
        //CCDirector::sharedDirector()->getTouchDispatcher()->decrementForcePrio(2);
        this->removeFromParentAndCleanup(true);
    }
    static ConfirmarCompra* create(CCArray* information) {
        auto r = new ConfirmarCompra;
        r->info = information;
        if (r && r->init()) r->autorelease();
        else CC_SAFE_DELETE(r);
        return r;
    }
};


std::string itemsString = "";

class DailyShop : public CCLayer {
    CCLayer* moveLayer;
    CCLabelBMFont* timer;
    CCMenuItemSpriteExtra* arrow;
    CCMenuItemSpriteExtra* arrow2;
    int limite = 50;
    int limitePage = 0;
    int actualPage = 0;
    CCSprite* loading;
    bool isReloading = false;
    float posX = 0;

public:
    bool init() {
        defineIconsRarity();

        auto size = CCDirector::sharedDirector()->getWinSize();

        this->setKeypadEnabled(true);

        auto layer = CCLayer::create();

        auto menu = CCMenu::create();
        menu->setPosition(0, 0);

        auto f = CCSprite::create("GJ_gradientBG.png");
		auto f_ = f->getContentSize();
		f->setScaleX(size.width / f_.width);
        f->setScaleY(size.height / f_.height);
		f->setPosition({ size.width / 2, size.height / 2 });
        f->setColor({ 0, 102, 255 });
		this->addChild(f, -1);

        auto gCL = CCLayerGradient::create();
        gCL->setStartColor({ 0, 255, 255 });
        gCL->setEndColor({ 0, 0, 0 });
        gCL->setStartOpacity(100);
        gCL->setEndOpacity(0);
        gCL->setAnchorPoint({ 0, 1 });
        gCL->runAction(CCRepeatForever::create(CCSequence::createWithTwoActions(CCEaseInOut::create(CCFadeTo::create(3, 150), 2), CCEaseInOut::create(CCFadeTo::create(3, 255), 2))));
        this->addChild(gCL);

        auto a = CCLayerColor::create({ 0, 0, 0, 150 });
        a->setContentSize({ size.width, 40 });
        a->setPosition({ size.width / 2 - a->getContentSize().width / 2, 15 - a->getContentSize().height / 2 });
        this->addChild(a);

        auto note = CCLabelBMFont::create("Note: These items are cosmetics only and do not confer any advantage.", "chatFont.fnt");
        note->setScale(.6f);
        note->setOpacity(125);
        note->setPosition({ size.width / 2, 20 });
        layer->addChild(note);

        this->addChild(MenuSelector::create(1));

        auto infoBtn = CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png"), this, menu_selector(DailyShop::onInfo));
        infoBtn->setPosition({ 18, size.height - 17 });
        menu->addChild(infoBtn);

        auto orbs = CCSprite::createWithSpriteFrameName("currencyOrbIcon_001.png");
        orbs->setScale(.8f);
        orbs->setPosition({ size.width - 20, size.height - 17 });
        layer->addChild(orbs, 1);

        /* for some reason particles can crash
        auto particle = CCParticleSystemQuad::create("keyEffect.plist", false);
        particle->setScale(.55f);
        particle->setPosition(orbs->getPosition());
        layer->addChild(particle);*/

        m_moneyLabel = CCLabelBMFont::create(CCString::createWithFormat("%i", GameStatsManager::sharedState()->getStat("14"))->getCString(), "bigFont.fnt");
        m_moneyLabel->setAnchorPoint({ 1, 0.5f });
        m_moneyLabel->limitLabelWidth(70, .45f, 0);
        m_moneyLabel->setPosition({ orbs->getPositionX() - 12, orbs->getPositionY() + 1 });
        layer->addChild(m_moneyLabel, 1);

        auto c = CCLayerColor::create({ 0, 0, 0, 75 });
        c->setContentSize({ 100, 23 });
        c->setPosition({ m_moneyLabel->getPositionX() - c->getContentSize().width + 24, m_moneyLabel->getPositionY() - a->getContentSize().height / 2 + 8 });
        this->addChild(c);

        timer = CCLabelBMFont::create("00:00:00", "chatFont.fnt");
        timer->setPosition({ size.width / 2, size.height / 2 + 117 });
        timer->setScale(.75f);
        layer->addChild(timer);

        auto sp = CCSprite::createWithSpriteFrameName("navArrowBtn_001.png");
        arrow = CCMenuItemSpriteExtra::create(sp, this, menu_selector(DailyShop::onNext));
        arrow->setPosition({ size.width + 20, size.height / 2 });
        menu->addChild(arrow);

        auto sp2 = CCSprite::createWithSpriteFrameName("navArrowBtn_001.png");
        sp2->setFlipX(true);
        arrow2 = CCMenuItemSpriteExtra::create(sp2, this, menu_selector(DailyShop::onBack));
        arrow2->setPosition({ -40, size.height / 2 });
        menu->addChild(arrow2);

        loading = CCSprite::create("loadingCircle.png");
        auto bf = ccBlendFunc{ GL_ONE, GL_ONE };
        loading->setBlendFunc(bf);
        loading->setPosition(size / 2);
        loading->runAction(CCRepeatForever::create(CCRotateBy::create(1, 360)));
        this->addChild(loading, 10);

        layer->addChild(menu);
        this->addChild(layer, 1);

        if (saveTime <= 0) {
            this->getShop();
        }
        else {
            this->updateShop();
        }

        return true;
    }
    void onInfo(CCObject*) {
        const char* platform = "Windows";
        #ifdef GEODE_IS_ANDROID64
            platform = "Android64";
        #endif
        #ifdef GEODE_IS_ANDROID32
            platform = "Android32";
        #endif

        auto v = geode::Mod::get()->getVersion();
        FLAlertLayer::create("Info", CCString::createWithFormat("Maybe in futures versions i will add 'death sounds' and 'menu loops', but i dont know\n\n[Mod version]\n<cy>%i.%i.%i - %s</c>", (int)v.getMajor(), (int)v.getMinor(), (int)v.getPatch(), platform)->getCString(), "OK")->show();
    }
    void generateItemShop() {
        std::vector<int> itemsType = {1, 2, 3, 4, 5, 6, 7, 8, 98, 99, 100, 101};
        std::unordered_set<int> selectedItems;

        std::time_t now = std::time(nullptr);
        std::tm* localTime = std::localtime(&now);

        std::mt19937 rng(((31 * localTime->tm_mday) * localTime->tm_mon) * localTime->tm_year);
        std::uniform_int_distribution<int> dist2(0, itemsType.size() - 1);

        itemsString = "";

        while (selectedItems.size() < 20) {
            ItemType itemType = static_cast<ItemType>(itemsType[dist2(rng)]);

            std::uniform_int_distribution<int> dist(0, getMaxIconForType(itemType));

            int itemID = dist(rng);
            if (itemID <= 1) itemID = 2;
            if (itemID > getMaxIconForType(itemType)) itemID = getMaxIconForType(itemType);

            if (selectedItems.find(itemID) == selectedItems.end()) {
                selectedItems.insert(itemID);
                itemsString += CCString::createWithFormat("a,%i,%i,%i|", itemID, itemType, getRarity(itemID, itemType))->getCString();
            }
        }

        itemsString = itemsString.substr(0, itemsString.size() - 1);
    }
    void removeMoveLayer() {
        if (moveLayer) {
            auto scene = CCDirector::sharedDirector()->getRunningScene();

            if (scene->getChildrenCount() > 1)
                for (int i = 1; i < scene->getChildrenCount(); i++) {
                    reinterpret_cast<ConfirmarCompra*>(scene->getChildren()->objectAtIndex(i))->onClose(nullptr);
                }

            moveLayer->stopAllActions();
            moveLayer->removeFromParentAndCleanup(true);

            moveLayer = nullptr;
        }
    }
    void updateShop() {
        loading->setVisible(false);

        this->removeMoveLayer();
        moveLayer = CCLayer::create();
        this->addChild(moveLayer);

        auto menu2 = CCMenu::create();
        menu2->setPosition(0, 0);

        auto size = CCDirector::sharedDirector()->getWinSize();
        CCArray* arr;

        if (itemsString.find("|")) {
            arr = splitToCCArray(itemsString, '|');
            limite = arr->count();
        }
        else {
            arr = splitToCCArray(itemsString, ',');
            limite = 1;
        }

        float padX = 0; int veces = 0;
        for (int i = 1; i <= limite; i++) {
            CCArray* itemInfo;

            if (itemsString.find("|"))
                itemInfo = splitToCCArray(arr->stringAtIndex(i - 1)->getCString(), ',');
            else
                itemInfo = arr;

            // itemInfo->stringAtIndex(0)->getCString();
            int itemID = itemInfo->stringAtIndex(1)->intValue();
            ItemType itemTipo = (ItemType)itemInfo->stringAtIndex(2)->intValue();
            int rarity = itemInfo->stringAtIndex(3)->intValue();
            std::string itemNam = CCString::createWithFormat("%s %i", getNameFromItemType(itemTipo), itemID)->getCString();

            bool comprado = false;
            if (itemTipo > 99)
                comprado = GameManager::sharedState()->isColorUnlocked(itemID, (UnlockType)(itemTipo - 98));
            else
                comprado = GameManager::sharedState()->isIconUnlocked(itemID, (IconType)itemTipo);


            auto bg = CCSprite::create("DS_itemBG.png"_spr);
            bg->setColor(colorFromRarity(rarity));
            bg->setPosition({ size.width / 2 - 175 + padX, size.height / 2 });
            moveLayer->addChild(bg, -1);

            int precio_count = priceFromRarity(rarity);
            auto orbs = CCSprite::createWithSpriteFrameName("currencyOrbIcon_001.png");
            if (comprado) {
                orbs = CCSprite::createWithSpriteFrameName("GJ_completesIcon_001.png");
                orbs->setPosition({ bg->getPositionX() + bg->getContentSize().width / 2 - 18 , bg->getPositionY() + bg->getContentSize().height / 2 - 15 });
            }
            else {
                orbs->setPosition({ bg->getPositionX() - bg->getContentSize().width / 2 + 15 , bg->getPositionY() + bg->getContentSize().height / 2 - 15 });

                auto precio = CCLabelBMFont::create(CCString::createWithFormat("%i", precio_count)->getCString(), "bigFont.fnt");
                precio->setAnchorPoint({ 0, 0.5f });
                precio->limitLabelWidth(100, .4f, 0);
                precio->setPosition({ orbs->getPositionX() + 12, orbs->getPositionY() + 1 });
                moveLayer->addChild(precio);
            }
            orbs->setScale(.8f);
            moveLayer->addChild(orbs);

            auto item = nodeFromItemType(itemTipo, itemID);
            item->setPosition({ bg->getPositionX(), bg->getPositionY() + 20 });
            item->setScale(1.5f);
            moveLayer->addChild(item);

            auto shadow = CCSprite::createWithSpriteFrameName("chest_shadow_001.png");
            shadow->setPosition({ item->getPositionX(), item->getPositionY() - 22 });
            shadow->setScale(.675f);
            shadow->setOpacity(90);
            moveLayer->addChild(shadow, -1);

            auto name = CCLabelBMFont::create(itemNam.c_str(), "chatFont.fnt");
            name->limitLabelWidth(bg->getContentSize().width - 20, 1, 0);
            name->setPosition({ bg->getPositionX(), bg->getPositionY() - bg->getContentSize().height / 2 + 75 });
            moveLayer->addChild(name);

            auto rarityName = CCLabelBMFont::create(nameFromRarity(rarity), "chatFont.fnt");
            rarityName->limitLabelWidth(bg->getContentSize().width - 10, 1, 0);
            rarityName->setPosition({ bg->getPositionX(), bg->getPositionY() - bg->getContentSize().height / 2 + 54 });
            rarityName->setColor(colorFromRarity(rarity));
            moveLayer->addChild(rarityName);

            auto spr = ButtonSprite::create("View", 50, true, "bigFont.fnt", "GJ_button_01.png", 25, 0.6f);
            if (comprado) spr = ButtonSprite::create("Owned", 50, true, "bigFont.fnt", "GJ_button_04.png", 25, 0.8f);
            spr->setScale(.9f);
            auto buy = CCMenuItemSpriteExtra::create(spr, this, menu_selector(DailyShop::onBuy));
            buy->setUserObject(CCString::createWithFormat("%s,%i,%i,%i,%i", name->getString(), itemID, rarity, precio_count, itemTipo));
            buy->setPosition({ bg->getPositionX(), bg->getPositionY() - bg->getContentSize().height / 2 + 23 });
            menu2->addChild(buy);

            padX += 116;
            if (i % 4 == 0) {
                veces++;
                padX = size.width * veces;
            }
        }

        moveLayer->addChild(menu2);

        actualPage = 0;
        moveLayer->setPosition({ 0, 0 });

        this->updatePage();
        this->scheduleUpdate();
        this->setTouchEnabled(true);
        this->setTouchMode(ccTouchesMode::kCCTouchesOneByOne);
    }
    void getShop() {
        std::time_t now = std::time(nullptr);
        std::tm midnight = *std::localtime(&now);

        midnight.tm_hour = 23;
        midnight.tm_min = 59;
        midnight.tm_sec = 59;

        saveTime = std::mktime(&midnight);

        this->generateItemShop();
        this->updateShop();
    }
    void ccTouchMoved(CCTouch* touch, CCEvent* event) {
        if (moveLayer)
            moveLayer->setPositionX(moveLayer->getPositionX() + touch->getDelta().x);
    }
    void ccTouchEnded(CCTouch* touch, CCEvent* event) {
        if (moveLayer) {
            auto xSize = CCDirector::sharedDirector()->getWinSize().width;

            auto target_x = -xSize * actualPage;
	
	        if (moveLayer->getPositionX() < target_x - xSize / 6) {
                actualPage += 1;
                if (actualPage > limitePage) actualPage = limitePage;
	            updatePage(2);
            }
	        else if (moveLayer->getPositionX() > target_x + xSize / 6) {
                actualPage -= 1;
                if (actualPage < 0) actualPage = 0;
	            updatePage(1);
            }
            else updatePage();
        }
    }
    void update(float dt) {
        std::time_t timeLeft = saveTime - time(0);

        if (timeLeft <= 0) {
            if (!isReloading) {
                this->removeMoveLayer();

                loading->setVisible(true);
                this->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(0.5f), CCCallFunc::create(this, callfunc_selector(DailyShop::getShop))));
                isReloading = true;
            }
        }
        else {
            //int days = timeLeft / (24 * 60 * 60);
            int hours = (timeLeft % (24 * 60 * 60)) / (60 * 60);
            int minutes = (timeLeft % (60 * 60)) / 60;
            int seconds = timeLeft % 60;

            timer->setString(CCString::createWithFormat("Next item shop in: %02d:%02d:%02d", hours, minutes, seconds)->getCString());
        }
    }
    void onNext(CCObject* a) {
        if (limite > 4) {
            actualPage++;
            if (actualPage > limitePage) actualPage = limitePage;

            this->updatePage(2);
        }
    }
    void onBack(CCObject*) {
        if (limite > 4) {
            actualPage--;
            if (actualPage < 0) actualPage = 0;

            this->updatePage(1);
        }
    }
    void runActionWithTag(CCNode* nodo, CCFiniteTimeAction* action, int tag) {
        action->setTag(tag);
        nodo->runAction(action);
    }
    void updatePage(int _tipo = 0) {
        auto size = CCDirector::sharedDirector()->getWinSize();

        limitePage = 0;
        for (int i = 1; i < limite; i++) {
            if (i % 4 == 0) limitePage++;
        }

        if (limitePage > 0) { // later i will fix that
            if (_tipo == 1)
                arrow2->stopActionByTag(6);
            if (_tipo == 2)
                arrow->stopActionByTag(6);

            if (actualPage == 0) {
                runActionWithTag(arrow2, CCEaseElasticOut::create(CCMoveTo::create(1.0f, { -30, size.height / 2 }), 1.8f), 6);
                runActionWithTag(arrow, CCSequence::createWithTwoActions(CCDelayTime::create(0.25f), CCEaseElasticOut::create(CCMoveTo::create(1.0f, { size.width - 30, size.height / 2 }), 1.8f)), 6);
            }
            else if (actualPage == limitePage) {
                runActionWithTag(arrow2, CCSequence::createWithTwoActions(CCDelayTime::create(0.25f), CCEaseElasticOut::create(CCMoveTo::create(1.0f, { 30, size.height / 2 }), 1.8f)), 6);
                runActionWithTag(arrow, CCEaseElasticOut::create(CCMoveTo::create(1.0f, { size.width + 30, size.height / 2 }), 1.8f), 6);
            }
            else {
                runActionWithTag(arrow2, CCSequence::createWithTwoActions(CCDelayTime::create(0.25f), CCEaseElasticOut::create(CCMoveTo::create(1.0f, { 30, size.height / 2 }), 1.8f)), 6);
                runActionWithTag(arrow, CCSequence::createWithTwoActions(CCDelayTime::create(0.25f), CCEaseElasticOut::create(CCMoveTo::create(1.0f, { size.width - 30, size.height / 2 }), 1.8f)), 6);
            }

            if (moveLayer) {
                moveLayer->stopActionByTag(7);
                runActionWithTag(moveLayer, CCEaseElasticOut::create(CCMoveTo::create(1.0f, { 0 - size.width * actualPage, 0 }), 1.8f), 7);
            }
        }
        else {
            runActionWithTag(arrow2, CCEaseElasticOut::create(CCMoveTo::create(1.0f, { -50, size.height / 2 }), 1.8f), 6);
            runActionWithTag(arrow, CCEaseElasticOut::create(CCMoveTo::create(1.0f, { size.width + 30, size.height / 2 }), 1.8f), 6);
        }
        isReloading = false;
    }
    void onBuy(CCObject* s) {
        auto arr = splitToCCArray(reinterpret_cast<CCString*>(reinterpret_cast<CCMenuItemSpriteExtra*>(s)->getUserObject())->getCString(), ',');
        ConfirmarCompra::create(arr)->show();
    }
    void onSalir(CCObject*) {
        CCDirector::sharedDirector()->replaceScene(MenuLayer::scene(false));
    }
    void keyDown(enumKeyCodes key) {
        if (key == KEY_Escape || key == CONTROLLER_B)
            this->onSalir(nullptr);
        if (key == KEY_ArrowLeft || key == CONTROLLER_Left)
            this->onBack(nullptr);
        if (key == KEY_ArrowRight || key == CONTROLLER_Right)
            this->onNext(nullptr);
    }
    static CCScene* scene() {
        auto s = CCScene::create();
        s->addChild(DailyShop::create());
        return s;
    }
    CREATE_FUNC(DailyShop);
};

void MenuSelector::onAccion(CCObject* a) {
    auto menu = reinterpret_cast<CCMenuItemSpriteExtra*>(a)->getParent();

    for (int i = 0; i < 2; i++)
        static_cast<CCMenuItemToggler*>(menu->getChildByTag(i))->toggle(false);

    reinterpret_cast<CCMenuItemToggler*>(a)->toggle(true);

    int tag = reinterpret_cast<CCMenuItemSpriteExtra*>(a)->getTag();
    if (m_nToggled != tag) {
        switch (tag) {
        case 0:
            CCDirector::sharedDirector()->replaceScene(MenuLayer::scene(0));
            break;
        case 1:
            if (GJAccountManager::sharedState()->m_accountID > 0)
                CCDirector::sharedDirector()->replaceScene(DailyShop::scene());
            break;
        }
    }
}

class $modify(MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) return false;

		this->addChild(MenuSelector::create(0));

		return true;
	}
};
