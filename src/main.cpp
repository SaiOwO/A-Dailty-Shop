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

        auto s = GameStatsManager::sharedState();

        for (int i = 5; i <= getMaxIconForType(Cube); i++) {
            if (i > 4 && i <= 142) m_cubesRarity->setObject(CCString::create("0"), i);
            else if (i > 142) m_cubesRarity->setObject(CCString::create("2"), i);
            else m_cubesRarity->setObject(CCString::create("1"), i);

            int iconID = 2000 + i;
            s->addStoreItem(iconID, 9999, 1, priceFromRarity(getRarity(i, Cube)), (ShopType)10);
        }
        for (int i = 2; i <= getMaxIconForType(Ship); i++) {
            if (i > 1 && i <= 21) m_shipsRarity->setObject(CCString::create("0"), i);
            else if (i > 51) m_shipsRarity->setObject(CCString::create("2"), i);
            else m_shipsRarity->setObject(CCString::create("1"), i);

            int iconID = 4000 + i;
            s->addStoreItem(iconID, 9999, 1, priceFromRarity(getRarity(i, Ship)), (ShopType)10);
        }
        for (int i = 2; i <= getMaxIconForType(Ball); i++) {
            if (i > 1 && i <= 22) m_ballsRarity->setObject(CCString::create("0"), i);
            else if (i > 43) m_ballsRarity->setObject(CCString::create("2"), i);
            else m_ballsRarity->setObject(CCString::create("1"), i);

            int iconID = 6000 + i;
            s->addStoreItem(iconID, 9999, 1, priceFromRarity(getRarity(i, Ball)), (ShopType)10);
        }
        for (int i = 2; i <= getMaxIconForType(Ufo); i++) {
            if (i > 1 && i <= 20) m_ufosRarity->setObject(CCString::create("0"), i);
            else if (i > 35) m_ufosRarity->setObject(CCString::create("2"), i);
            else m_ufosRarity->setObject(CCString::create("1"), i);

            int iconID = 8000 + i;
            s->addStoreItem(iconID, 9999, 1, priceFromRarity(getRarity(i, Ufo)), (ShopType)10);
        }
        for (int i = 2; i <= getMaxIconForType(Wave); i++) {
            if (i > 1 && i <= 23) m_wavesRarity->setObject(CCString::create("0"), i);
            else if (i > 35) m_wavesRarity->setObject(CCString::create("2"), i);
            else m_wavesRarity->setObject(CCString::create("1"), i);

            int iconID = 10000 + i;
            s->addStoreItem(iconID, 9999, 1, priceFromRarity(getRarity(i, Wave)), (ShopType)10);
        }
        for (int i = 2; i <= getMaxIconForType(Robot); i++) {
            if (i > 1 && i <= 6) m_robotsRarity->setObject(CCString::create("0"), i);
            else if (i > 26) m_robotsRarity->setObject(CCString::create("2"), i);
            else m_robotsRarity->setObject(CCString::create("1"), i);

            int iconID = 12000 + i;
            s->addStoreItem(iconID, 9999, 1, priceFromRarity(getRarity(i, Robot)), (ShopType)10);
        }
        for (int i = 2; i <= getMaxIconForType(Spider); i++) {
            if (i > 1 && i <= 4) m_spidersRarity->setObject(CCString::create("0"), i);
            else if (i > 17) m_spidersRarity->setObject(CCString::create("2"), i);
            else m_spidersRarity->setObject(CCString::create("1"), i);

            int iconID = 14000 + i;
            s->addStoreItem(iconID, 9999, 1, priceFromRarity(getRarity(i, Spider)), (ShopType)10);
        }
        for (int i = 2; i <= getMaxIconForType(Swing); i++) {
            m_swingsRarity->setObject(CCString::create("2"), i);

            int iconID = 16000 + i;
            s->addStoreItem(iconID, 9999, 1, priceFromRarity(getRarity(i, Swing)), (ShopType)10);
        }
        for (int i = 2; i <= getMaxIconForType(Jetpack); i++) {
            m_jetpacksRarity->setObject(CCString::create("1"), i);

            int iconID = 18000 + i;
            s->addStoreItem(iconID, 9999, 1, priceFromRarity(getRarity(i, Jetpack)), (ShopType)10);
        }
        for (int i = 2; i <= getMaxIconForType(Special); i++) {
            if (i == 2) m_specialsRarity->setObject(CCString::create("3"), i);
            else m_specialsRarity->setObject(CCString::create("0"), i);

            int iconID = 198000 + i;
            s->addStoreItem(iconID, 9999, 1, priceFromRarity(getRarity(i, Special)), (ShopType)10);
        }
        for (int i = 2; i <= getMaxIconForType(DeathEffect); i++) {
            m_effectsRarity->setObject(CCString::create("0"), i);

            int iconID = 196000 + i;
            s->addStoreItem(iconID, 9999, 1, priceFromRarity(getRarity(i, DeathEffect)), (ShopType)10);
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

        auto titulo = CCLabelBMFont::create("Confirm purchase", "bigFont.fnt");
        titulo->limitLabelWidth(200, 0.7f, 0);
        titulo->setPosition({ bg->getPositionX(), bg->getPositionY() + bg->getContentSize().height / 2 - 20 });
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

        itemTipo = (ItemType)info->stringAtIndex(4)->intValue();
        itemID = info->stringAtIndex(1)->intValue();

        auto item = nodeFromItemType(itemTipo, itemID);
        item->setScale(1.4f);
        item->setPosition({ bgI->getPositionX(), bgI->getPositionY() - 10 });
        m_mainLayer->addChild(item);
        
        auto shadow = CCSprite::createWithSpriteFrameName("chest_shadow_001.png");
        shadow->setPosition({ item->getPositionX(), item->getPositionY() - 20 });
        shadow->setScale(.575f);
        shadow->setOpacity(90);
        m_mainLayer->addChild(shadow, -1);
        
        auto orbs = CCSprite::createWithSpriteFrameName("currencyOrbIcon_001.png");
        orbs->setScale(.8f);
        orbs->setPosition({ bgI->getPositionX() - bgI->getContentSize().width / 2 + 15 , bgI->getPositionY() - bgI->getContentSize().height / 2 + 15 });
        m_mainLayer->addChild(orbs);

        price = info->stringAtIndex(3)->intValue();
        auto precio = CCLabelBMFont::create(CCString::createWithFormat("%i", price)->getCString(), "bigFont.fnt");
        precio->setAnchorPoint({ 0, 0.5f });
        precio->limitLabelWidth(100, .4f, 0);
        precio->setPosition({ orbs->getPositionX() + 12, orbs->getPositionY() + 1 });
        m_mainLayer->addChild(precio);

        auto desc = TextArea::create(CCString::createWithFormat("Are you sure you want to buy this <cg>%s</c> for <cy>%s</c> <cl>mana orbs</c>?\n<cr>(This action is unreversible)</c>", getNameFromItemType(itemTipo), precio->getString())->getCString(), "chatFont.fnt",  1, 300, { 0.5f, 0.5f }, 20, false);
        desc->setPosition({ bg->getPositionX(), bg->getPositionY() + 65 });
        desc->setScale(.7f);
        m_mainLayer->addChild(desc);

        auto menu3 = CCMenu::create();

        auto cancel = ButtonSprite::create("Cancel", 70, false, "goldFont.fnt", "GJ_button_06.png", 0.0f, 1);
        auto cancelBtn = CCMenuItemSpriteExtra::create(cancel, this, menu_selector(ConfirmarCompra::onClose));
        menu3->addChild(cancelBtn);

        auto submit = ButtonSprite::create("Buy!", 70, false, "goldFont.fnt", "GJ_button_01.png", 0.0f, 1);
        auto submitBtn = CCMenuItemSpriteExtra::create(submit, this, menu_selector(ConfirmarCompra::onBuy));
        menu3->addChild(submitBtn);

        menu3->setPosition({ bg->getPositionX(), bg->getPositionY() - bg->getContentSize().height / 2 + 25 });
        menu3->alignItemsHorizontallyWithPadding(15);
        menu3->setTouchPriority(-504);
        m_mainLayer->addChild(menu3, 10);

        this->addChild(m_mainLayer);
        return true;
    }
    void onBuy(CCObject*) {
        auto gst = GameStatsManager::sharedState();
        if (gst->getStat("14") - price >= 0) {
            GameManager::sharedState()->unlockIcon(itemID, (IconType)itemTipo);
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
        orbs->setPosition({ size.width - 15, size.height - 17 });
        layer->addChild(orbs, 1);

        auto particle = CCParticleSystemQuad::create("keyEffect.plist", false);
        particle->setPosition(orbs->getPosition());
        layer->addChild(particle);

        m_moneyLabel = CCLabelBMFont::create(CCString::createWithFormat("%i", GameStatsManager::sharedState()->getStat("14"))->getCString(), "bigFont.fnt");
        m_moneyLabel->setAnchorPoint({ 1, 0.5f });
        m_moneyLabel->limitLabelWidth(70, .45f, 0);
        m_moneyLabel->setPosition({ orbs->getPositionX() - 12, orbs->getPositionY() + 1 });
        layer->addChild(m_moneyLabel, 1);

        auto c = CCLayerColor::create({ 0, 0, 0, 75 });
        c->setContentSize({ 100, 23 });
        c->setPosition({ m_moneyLabel->getPositionX() - c->getContentSize().width + 24, m_moneyLabel->getPositionY() - a->getContentSize().height / 2 + 8 });
        this->addChild(c);

        timer = CCLabelBMFont::create("00:00:00:00", "chatFont.fnt");
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
        FLAlertLayer::create("Info", CCString::createWithFormat("Maybe in futures versions i will add 'death sounds' and 'menu loops', but i dont know\n\n[Mod version]\n<cy>%i.%i.%i - %s</c>", (int)v.getMajor(), (int)v.getPatch(), (int)v.getMinor(), platform)->getCString(), "OK")->show();
    }
    void generateItemShop() {
        std::vector<int> itemsType = {1,2,3,4,5,6,7,8,98,99};
        
        std::time_t now = std::time(nullptr);
        std::tm* localTime = std::localtime(&now);

        std::mt19937 rng(((31 * localTime->tm_mday) * localTime->tm_mon) * localTime->tm_year);
        std::uniform_int_distribution<int> dist2(0, itemsType.size() - 1);

        itemsString = "";

        for (int i = 0; i < 16; ++i) {
            ItemType itemType = (ItemType)itemsType[dist2(rng)];

            std::uniform_int_distribution<int> dist(0, getMaxIconForType(itemType));

            int itemID = dist(rng);
            if (itemID <= 1) itemID = 2;
            if (itemID > getMaxIconForType(itemType)) itemID = getMaxIconForType(itemType);

            itemsString += CCString::createWithFormat("a,%i,%i,%i|", itemID, itemType, getRarity(itemID, itemType))->getCString();
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
            bool comprado = GameManager::sharedState()->isIconUnlocked(itemID, (IconType)itemTipo);

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

            auto spr = ButtonSprite::create("View", 40, true, "bigFont.fnt", "GJ_button_01.png", 0, 0.8f);
            if (comprado) spr = ButtonSprite::create("Owned", 50, true, "bigFont.fnt", "GJ_button_04.png", 25, 0.8f);
            spr->setScale(.9f);
            if (!comprado) {
                auto buy = CCMenuItemSpriteExtra::create(spr, this, menu_selector(DailyShop::onBuy));
                buy->setUserObject(CCString::createWithFormat("%s,%i,%i,%i,%i", name->getString(), itemID, rarity, precio_count, itemTipo));
                buy->setPosition({ bg->getPositionX(), bg->getPositionY() - bg->getContentSize().height / 2 + 23 });
                menu2->addChild(buy);
            }
            else {
                spr->setPosition({ bg->getPositionX(), bg->getPositionY() - bg->getContentSize().height / 2 + 23 });
                menu2->addChild(spr);
            }
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
    }
    bool isReloading = false;
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
    void keyBackClicked() {
        this->onSalir(nullptr);
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