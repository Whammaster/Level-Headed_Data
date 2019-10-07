#include "Graphics_Ripper.h"
#include "../../../Level-Headed/SMB1/Common_SMB1_Files/Fix_Strings.h"
#include <assert.h>
#include <QDebug>
#include <QDir>
#include <QFileInfo>

Graphics_Ripper::Graphics_Ripper(const QString &applicationLocation, const QString &originalFileLocation, const QString &patchFileLocation, Hexagon_Interface *hexagon) {
    assert(hexagon);
    this->applicationLocation = applicationLocation;
    this->originalFileLocation = originalFileLocation;
    this->patchFileLocation = patchFileLocation;
    this->hexagon = hexagon;
    this->palettesDisabled = false;
    this->outputFile = nullptr;
    this->originalFile = nullptr;
    this->workingFile = nullptr;
    this->baseFile = nullptr;
}

Graphics_Ripper::~Graphics_Ripper() {
    this->Close_Files();
}

bool Graphics_Ripper::Rip_All() {
    //Rip all except bridge and chain
    if (!this->Rip_Air_Bubble()) return false;
    if (!this->Rip_Blooper()) return false;
    if (!this->Rip_Bowser()) return false;
    if (!this->Rip_Bowser_Fire()) return false;
    if (!this->Rip_Bullet_Bill()) return false;
    if (!this->Rip_Buzzy_Beetle()) return false;
    if (!this->Rip_Castle_Flag()) return false;
    if (!this->Rip_Chain()) return false;
    if (!this->Rip_Cheep_Cheep()) return false;
    if (!this->Rip_Coin_Animation()) return false;
    if (!this->Rip_Explosion()) return false;
    if (!this->Rip_Fireball()) return false;
    if (!this->Rip_Flagpole_Flag()) return false;
    if (!this->Rip_Goomba()) return false;
    if (!this->Rip_Hammer_Bro()) return false;
    if (!this->Rip_Jump_Spring()) return false;
    if (!this->Rip_Koopa()) return false;
    if (!this->Rip_Lakitu()) return false;
    if (!this->Rip_Lift()) return false;
    if (!this->Rip_Mario()) return false;
    if (!this->Rip_One_Up_Font()) return false;
    if (!this->Rip_Peach()) return false;
    if (!this->Rip_Piranha_Plant()) return false;
    if (!this->Rip_Podoboo()) return false;
    if (!this->Rip_Score_Font()) return false;
    if (!this->Rip_Sky_Lift()) return false;
    if (!this->Rip_Spiny()) return false;
    if (!this->Rip_Spiny_Egg()) return false;
    if (!this->Rip_Toad()) return false;
    if (!this->Rip_Axe()) return false;
    if (!this->Rip_Brick_Block()) return false;
    if (!this->Rip_Bowser_Bridge()) return false;
    if (!this->Rip_Bridge()) return false;
    if (!this->Rip_Bullet_Bill_Cannon()) return false;
    if (!this->Rip_Castle_Block()) return false;
    if (!this->Rip_Cloud_Block()) return false;
    if (!this->Rip_Coin()) return false;
    if (!this->Rip_Coin_Icon()) return false;
    if (!this->Rip_Coral()) return false;
    if (!this->Rip_Fire_Flower()) return false;
    if (!this->Rip_Flagpole()) return false;
    if (!this->Rip_Font()) return false;
    if (!this->Rip_Mushroom_Powerup()) return false;
    if (!this->Rip_Mushroom_Platform()) return false;
    if (!this->Rip_Overworld_Block()) return false;
    if (!this->Rip_Pipe()) return false;
    if (!this->Rip_Question_Block()) return false;
    if (!this->Rip_Rope()) return false;
    if (!this->Rip_Selector_Icon()) return false;
    if (!this->Rip_Solid_Block()) return false;
    if (!this->Rip_Starman()) return false;
    if (!this->Rip_Tree_Platform()) return false;
    if (!this->Rip_Underwater_Block()) return false;
    if (!this->Rip_Vine()) return false;
    if (!this->Rip_Water()) return false;
    return true;
}

bool Graphics_Ripper::Rip_Air_Bubble() {
    if (!this->Apply_Patch()) return false;
    if (!this->Write_Sprite_Tiles_To_Working_File(QByteArray(1, static_cast<char>(0x75)))) return false;
    return this->Create_Patch("Air Bubble");
}

bool Graphics_Ripper::Rip_Blooper() {
    if (!this->Apply_Patch()) return false;
    bool sprite = true;
    QStack<qint64> offsets; offsets.push(0x678A); offsets.push(0x6790);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Blooper");
}

bool Graphics_Ripper::Rip_Bowser() {
    if (!this->Apply_Patch()) return false;
    bool sprite = true;
    QStack<qint64> offsets; offsets.push(0x6820); offsets.push(0x6826); offsets.push(0x682C); offsets.push(0x6832);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    if (!this->Write_Data_To_Working_File(0x0D60, 3)) return false; //write the palette
    return this->Create_Patch("Bowser");
}

bool Graphics_Ripper::Rip_Bowser_Fire() {
    if (!this->Apply_Patch()) return false;
    if (!this->Write_Sprite_Tiles_To_Working_File(QByteArray::fromHex(QString("515253").toLatin1()))) return false;
    return this->Create_Patch("Bowser Fire");
}

bool Graphics_Ripper::Rip_Bullet_Bill() {
    if (!this->Apply_Patch()) return false;
    bool sprite = true;
    QStack<qint64> offsets; offsets.push(0x6838);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Bullet Bill");
}

bool Graphics_Ripper::Rip_Buzzy_Beetle() {
    if (!this->Apply_Patch()) return false;
    bool sprite = true;
    QStack<qint64> offsets; offsets.push(0x674E); offsets.push(0x6754); offsets.push(0x67C0); offsets.push(0x67C6); offsets.push(0x67CC); offsets.push(0x67D2);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Buzzy Beetle");
}

bool Graphics_Ripper::Rip_Castle_Flag() {
    if (!this->Apply_Patch()) return false;
    if (!this->Write_Sprite_Tiles_To_Working_File(QByteArray::fromHex(QString("54555657").toLatin1()))) return false;
    return this->Create_Patch("Castle Flag");
}

bool Graphics_Ripper::Rip_Cheep_Cheep() {
    if (!this->Apply_Patch()) return false;
    bool sprite = true;
    QStack<qint64> offsets; offsets.push(0x6796); offsets.push(0x679C);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Cheep Cheep");
}

bool Graphics_Ripper::Rip_Coin_Animation() {
    if (!this->Apply_Patch()) return false;
    if (!this->Write_Sprite_Tiles_To_Working_File(QByteArray::fromHex(QString("60616263").toLatin1()))) return false;
    return this->Create_Patch("Coin Animation");
}

bool Graphics_Ripper::Rip_Explosion() {
    if (!this->Apply_Patch()) return false;
    if (!this->Write_Sprite_Tiles_To_Working_File(QByteArray::fromHex(QString("666768").toLatin1()))) return false;
    return this->Create_Patch("Explosion");
}

bool Graphics_Ripper::Rip_Fireball() {
    if (!this->Apply_Patch()) return false;
    if (!this->Write_Sprite_Tiles_To_Working_File(QByteArray::fromHex(QString("6465").toLatin1()))) return false;
    return this->Create_Patch("Fireball");
}

bool Graphics_Ripper::Rip_Flagpole_Flag() {
    if (!this->Apply_Patch()) return false;
    if (!this->Write_Sprite_Tiles_To_Working_File(QByteArray::fromHex(QString("7E7F").toLatin1()))) return false;
    return this->Create_Patch("Flagpole Flag");
}

bool Graphics_Ripper::Rip_Goomba() {
    if (!this->Apply_Patch()) return false;
    bool sprite = true;
    QStack<qint64> offsets; offsets.push(0x67A2); offsets.push(0x67D8);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Goomba");
}

bool Graphics_Ripper::Rip_Hammer_Bro() {
    if (!this->Apply_Patch()) return false;
    bool sprite = true;
    QStack<qint64> offsets; offsets.push(0x67F6); offsets.push(0x67FC); offsets.push(0x6802); offsets.push(0x6808);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Hammer Bro");
}

bool Graphics_Ripper::Rip_Jump_Spring() {
    if (!this->Apply_Patch()) return false;

    //Jump Spring Sprite
    bool sprite = true;
    QStack<qint64> offsets; offsets.push(0x683E); offsets.push(0x6844); offsets.push(0x684A);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;

    //Brick Base
    sprite = false;
    offsets.push(0x0C5C); offsets.push(0x0C64);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Jump Spring");
}

bool Graphics_Ripper::Rip_Koopa() {
    if (!this->Apply_Patch()) return false;
    bool sprite = true;
    QStack<qint64> offsets; offsets.push(0x675A); offsets.push(0x6760); offsets.push(0x6766); offsets.push(0x676C); offsets.push(0x67A8); offsets.push(0x67AE); offsets.push(0x67B4); offsets.push(0x67BA);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Koopa");
}

bool Graphics_Ripper::Rip_Lakitu() {
    if (!this->Apply_Patch()) return false;
    bool sprite = true;
    QStack<qint64> offsets; offsets.push(0x67DE); offsets.push(0x67E4);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Lakitu");
}

bool Graphics_Ripper::Rip_Lift() {
    if (!this->Apply_Patch()) return false;
    if (!this->Write_Sprite_Tiles_To_Working_File(QByteArray::fromHex(QString("5B").toLatin1()))) return false;
    return this->Create_Patch("Lift");
}

bool Graphics_Ripper::Rip_Mario() {
    if (!this->Apply_Patch()) return false;

    //Write the Tile Order
    bool sprite = true;
    QStack<qint64> offsets; offsets.push(0x6E28); offsets.push(0x6E30); offsets.push(0x6E38); offsets.push(0x6E40); offsets.push(0x6E48); offsets.push(0x6E50); offsets.push(0x6E58); offsets.push(0x6E60); offsets.push(0x6E68);
    offsets.push(0x6E70); offsets.push(0x6E78); offsets.push(0x6E80); offsets.push(0x6E88); offsets.push(0x6E90); offsets.push(0x6E98); offsets.push(0x6EA0); offsets.push(0x6EA8); offsets.push(0x6EB0); offsets.push(0x6EB8);
    offsets.push(0x6EC0); offsets.push(0x6EC8); offsets.push(0x6ED0); offsets.push(0x6ED8); offsets.push(0x6EE0); offsets.push(0x6EE8); offsets.push(0x6EF0);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, true)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, true)) return false;

    //Write the Palette
    if (!this->Write_Data_To_Working_File(0x05E8, 3)) return false;
    if (!this->Write_Data_To_Working_File(0x05EC, 3)) return false;
    if (!this->Write_Data_To_Working_File(0x05F0, 3)) return false;
    return this->Create_Patch("Mario");
}

bool Graphics_Ripper::Rip_One_Up_Font() {
    if (!this->Apply_Patch()) return false;
    if (!this->Write_Sprite_Tiles_To_Working_File(QByteArray::fromHex(QString("FDFE").toLatin1()))) return false;
    return this->Create_Patch("Font One Up");
}

bool Graphics_Ripper::Rip_Peach() {
    if (!this->Apply_Patch()) return false;
    bool sprite = true;
    QStack<qint64> offsets; offsets.push(0x67EA);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Peach");
}

bool Graphics_Ripper::Rip_Piranha_Plant() {
    if (!this->Apply_Patch()) return false;
    bool sprite = true;
    QStack<qint64> offsets; offsets.push(0x680E); offsets.push(0x6814);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Piranha Plant");
}

bool Graphics_Ripper::Rip_Podoboo() {
    if (!this->Apply_Patch()) return false;
    bool sprite = true;
    QStack<qint64> offsets; offsets.push(0x681A);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Podoboo");
}

bool Graphics_Ripper::Rip_Score_Font() {
    if (!this->Apply_Patch()) return false;
    if (!this->Write_Sprite_Tiles_To_Working_File(QByteArray::fromHex(QString("50F6F7F8F9FAFB").toLatin1()))) return false;
    return this->Create_Patch("Font Score");
}

bool Graphics_Ripper::Rip_Sky_Lift() {
    if (!this->Apply_Patch()) return false;
    if (!this->Write_Sprite_Tiles_To_Working_File(QByteArray(1, static_cast<char>(0x75)))) return false;
    return this->Create_Patch("Lift Sky");
}

bool Graphics_Ripper::Rip_Spiny() {
    if (!this->Apply_Patch()) return false;
    bool sprite = true;
    QStack<qint64> offsets; offsets.push(0x6772); offsets.push(0x6778);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Spiny");
}

bool Graphics_Ripper::Rip_Spiny_Egg() {
    if (!this->Apply_Patch()) return false;
    bool sprite = true;
    QStack<qint64> offsets; offsets.push(0x677E); offsets.push(0x6784);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Spiny Egg");
}

bool Graphics_Ripper::Rip_Toad() {
    if (!this->Apply_Patch()) return false;
    bool sprite = true;
    QStack<qint64> offsets; offsets.push(0x67F0);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Toad");
}

bool Graphics_Ripper::Rip_Axe() {
    if (!this->Apply_Patch()) return false;
    bool sprite = false;
    QStack<qint64> offsets; offsets.push(0x0CB0);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Axe");
}

bool Graphics_Ripper::Rip_Brick_Block() {
    if (!this->Apply_Patch()) return false;
    bool sprite = false;
    QStack<qint64> offsets; offsets.push(0x0BD0); offsets.push(0x0BD4); offsets.push(0x0BD8); offsets.push(0x0BDC); offsets.push(0x0BE0); offsets.push(0x0C00); offsets.push(0x0C04); offsets.push(0x0C08);
    offsets.push(0x0C10); offsets.push(0x0C14); offsets.push(0x0C18); offsets.push(0x0C1C); offsets.push(0x0C20); offsets.push(0x0C24); offsets.push(0x0C28); offsets.push(0x0C2C); offsets.push(0x0C30); offsets.push(0x0C34);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Brick Block");
}

bool Graphics_Ripper::Rip_Bowser_Bridge() {
    if (!this->Apply_Patch()) return false;
    bool sprite = false;
    QStack<qint64> offsets; offsets.push(0x0C98);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Bowser Bridge");
}

bool Graphics_Ripper::Rip_Bridge() {
    if (!this->Apply_Patch()) return false;
    bool sprite = false;
    QStack<qint64> offsets; offsets.push(0x0B4C); offsets.push(0x0C48);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Bridge");
}

bool Graphics_Ripper::Rip_Bullet_Bill_Cannon() {
    if (!this->Apply_Patch()) return false;
    bool sprite = false;
    QStack<qint64> offsets; offsets.push(0x0C4C); offsets.push(0x0C50); offsets.push(0x0C54);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Bullet Bill Cannon");
}

bool Graphics_Ripper::Rip_Castle_Block() {
    if (!this->Apply_Patch()) return false;
    bool sprite = false;
    QStack<qint64> offsets; offsets.push(0x0C44);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Block Castle");
}

bool Graphics_Ripper::Rip_Chain() {
    if (!this->Apply_Patch()) return false;
    bool sprite = false;
    QStack<qint64> offsets; offsets.push(0x0B50);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Chain");
}

bool Graphics_Ripper::Rip_Cloud_Block() {
    if (!this->Apply_Patch()) return false;
    bool sprite = false;
    QStack<qint64> offsets; offsets.push(0x0C94);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Block Cloud");
}

bool Graphics_Ripper::Rip_Coin() {
    if (!this->Apply_Patch()) return false;
    bool sprite = false;
    QStack<qint64> offsets; offsets.push(0x0CA4); offsets.push(0x0CA8);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Coin");
}

bool Graphics_Ripper::Rip_Coin_Icon() {
    if (!this->Apply_Patch()) return false;
    if (!this->Write_Sprite_Tiles_To_Working_File(QByteArray::fromHex(QString("FF").toLatin1()))) return false;
    if (!this->Write_Background_Tiles_To_Working_File(QByteArray::fromHex(QString("2E").toLatin1()))) return false;
    return this->Create_Patch("Coin Icon");
}

bool Graphics_Ripper::Rip_Coral() {
    if (!this->Apply_Patch()) return false;
    bool sprite = false;
    QStack<qint64> offsets; offsets.push(0x0BA8);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Coral");
}

bool Graphics_Ripper::Rip_Fire_Flower() {
    if (!this->Apply_Patch()) return false;
    if (!this->Write_Sprite_Tiles_To_Working_File(QByteArray::fromHex(QString("D6D9").toLatin1()))) return false;
    return this->Create_Patch("Powerup Fire Flower");
}

bool Graphics_Ripper::Rip_Flagpole() {
    if (!this->Apply_Patch()) return false;
    bool sprite = false;
    QStack<qint64> offsets; offsets.push(0x0BB0); offsets.push(0x0BB4);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Flagpole");
}

bool Graphics_Ripper::Rip_Font() {
    if (!this->Apply_Patch()) return false;
    if (!this->Write_Background_Tiles_To_Working_File(QByteArray::fromHex(QString("000102030405060708090A0B0C0D0E0F101112131415161718191A1B1C1D1E1F2021222328292BAFCF").toLatin1()))) return false;
    return this->Create_Patch("Font");
}

bool Graphics_Ripper::Rip_Mushroom_Powerup() {
    if (!this->Apply_Patch()) return false;
    if (!this->Write_Sprite_Tiles_To_Working_File(QByteArray::fromHex(QString("76777879").toLatin1()))) return false;
    return this->Create_Patch("Powerup Mushroom");
}

bool Graphics_Ripper::Rip_Mushroom_Platform() {
    if (!this->Apply_Patch()) return false;
    bool sprite = false;
    QStack<qint64> offsets; offsets.push(0x0B84); offsets.push(0x0B88); offsets.push(0x0B8C); offsets.push(0x0BF8); offsets.push(0x0BFC);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Island Mushroom");
}

bool Graphics_Ripper::Rip_Overworld_Block() {
    if (!this->Apply_Patch()) return false;
    bool sprite = false;
    QStack<qint64> offsets; offsets.push(0x0C0C);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Block Overworld");
}

bool Graphics_Ripper::Rip_Pipe() {
    if (!this->Apply_Patch()) return false;
    bool sprite = false;
    QStack<qint64> offsets; offsets.push(0x0C68); offsets.push(0x0C6C); offsets.push(0x0B60); offsets.push(0x0B64); offsets.push(0x0B68); offsets.push(0x0B6C); offsets.push(0x0B70); offsets.push(0x0B74);
    offsets.push(0x0B90); offsets.push(0x0B94); offsets.push(0x0B98); offsets.push(0x0B9C); offsets.push(0x0BA0); offsets.push(0x0BA4);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Pipe");
}

bool Graphics_Ripper::Rip_Question_Block() {
    if (!this->Apply_Patch()) return false;
    bool sprite = false;
    QStack<qint64> offsets; offsets.push(0x0C9C); offsets.push(0x0CA0); offsets.push(0x0CAC);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Question Block");
}

bool Graphics_Ripper::Rip_Rope() {
    if (!this->Apply_Patch()) return false;
    bool sprite = false;
    QStack<qint64> offsets; offsets.push(0x0BBC); offsets.push(0x0BC0); offsets.push(0x0BC4); offsets.push(0x0BC8);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Rope");
}

bool Graphics_Ripper::Rip_Selector_Icon() {
    if (!this->Apply_Patch()) return false;
    if (!this->Write_Sprite_Tiles_To_Working_File(QByteArray::fromHex(QString("BE").toLatin1()))) return false;
    return this->Create_Patch("Selector Icon");
}

bool Graphics_Ripper::Rip_Solid_Block() {
    if (!this->Apply_Patch()) return false;
    bool sprite = false;
    QStack<qint64> offsets; offsets.push(0x0C40);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Solid Block");
}

bool Graphics_Ripper::Rip_Starman() {
    if (!this->Apply_Patch()) return false;
    if (!this->Write_Sprite_Tiles_To_Working_File(QByteArray::fromHex(QString("7DE4").toLatin1()))) return false;
    return this->Create_Patch("Starman");
}

bool Graphics_Ripper::Rip_Tree_Platform() {
    if (!this->Apply_Patch()) return false;
    bool sprite = false;
    QStack<qint64> offsets; offsets.push(0x0B78); offsets.push(0x0B7C); offsets.push(0x0B80); offsets.push(0x0BEC);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Island Tree");
}

bool Graphics_Ripper::Rip_Underwater_Block() {
    if (!this->Apply_Patch()) return false;
    bool sprite = false;
    QStack<qint64> offsets; offsets.push(0x0C60);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Block Underwater");
}

bool Graphics_Ripper::Rip_Vine() {
    if (!this->Apply_Patch()) return false;
    if (!this->Write_Sprite_Tiles_To_Working_File(QByteArray::fromHex(QString("E0E1E2").toLatin1()))) return false;
    return this->Create_Patch("Vine");
}

bool Graphics_Ripper::Rip_Water() {
    if (!this->Apply_Patch()) return false;
    bool sprite = false;
    QStack<qint64> offsets; offsets.push(0x0C8C);
    if (this->Does_Patch_Use_New_Tiles(offsets, sprite, false)) return true;
    if (!this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, false)) return false;
    return this->Create_Patch("Water");
}

bool Graphics_Ripper::Apply_Patch() {
    if (this->outputFile) return true; //patch already applied
    if (!this->Scan_For_Palette_Allowed()) return false;

    //Create the Patched file
    int lineNum = 0;
    QString outputLocation = this->applicationLocation+"/"+this->Get_Base_Name_From_Path(this->patchFileLocation)+".nes";
    if (this->hexagon->Apply_Hexagon_Patch(this->patchFileLocation, this->originalFileLocation, outputLocation, false, lineNum) != Hexagon_Error_Codes::OK) return false;
    this->outputFile = new QFile(outputLocation);
    if (!this->outputFile->open(QIODevice::ReadWrite)) return false;

    //Open the original file and create a working copy
    if (!this->Recreate_Working_File()) { this->Close_Files(); return false; }
    return true;
}

bool Graphics_Ripper::Create_Patch(const QString &sprite) {
    QDir dir(this->applicationLocation);
    dir.mkdir("Sprites");
    if (!dir.cd("Sprites")) return false;
    dir.mkdir(sprite);
    this->workingFile->flush();
    this->baseFile->flush();
    if (this->hexagon->Create_Hexagon_Patch(this->baseFileLocation, this->workingFileLocation, this->applicationLocation+"/Sprites/"+sprite+"/"+this->Get_Base_Name_From_Path(this->patchFileLocation)+".hexp", 5, false, false) != Hexagon_Error_Codes::OK) return false;
    return this->Recreate_Working_File();
}

void Graphics_Ripper::Close_Files() {
    if (this->outputFile) {
        this->outputFile->close();
        this->outputFile->remove();
    }
    delete this->outputFile;
    this->outputFile = nullptr;
    this->Close_Working_Files();
}

void Graphics_Ripper::Close_Working_Files() {
    if (this->originalFile) this->originalFile->close();
    if (this->workingFile) {
        this->workingFile->close();
        this->workingFile->remove();
    }
    if (this->baseFile) {
        this->baseFile->close();
        this->baseFile->remove();
    }
    delete this->originalFile;
    delete this->workingFile;
    delete this->baseFile;
    this->originalFile = nullptr;
    this->workingFile = nullptr;
    this->baseFile = nullptr;
    this->writtenSpriteTiles.clear();
    this->writtenBackgroundTiles.clear();
}

bool Graphics_Ripper::Does_Patch_Use_New_Tiles(qint64 offset, bool sprite, bool mario) {
    QStack<qint64> offsets;
    offsets.push(offset);
    return this->Does_Patch_Use_New_Tiles(offsets, sprite, mario);
}

bool Graphics_Ripper::Does_Patch_Use_New_Tiles(QStack<qint64> offsets, bool sprite, bool mario) {
    if (this->palettesDisabled) return true;

    //Read the old tiles
    QSet<char> tiles;
    QByteArray oldTiles;
    QStack<qint64> oldOffsets = offsets;
    if (sprite) tiles.insert(static_cast<char>(0xFC));
    else tiles.insert(static_cast<char>(0x24));
    int tileOrderSize = 4;
    if (sprite) tileOrderSize = 6;
    if (mario) { assert(sprite); tileOrderSize = 8; }
    while (!oldOffsets.isEmpty()) {
        qint64 offset = oldOffsets.pop();
        assert(this->originalFile->seek(offset));
        QByteArray oldTiles = this->originalFile->read(tileOrderSize);
        assert(oldTiles.size() == tileOrderSize);
        for (char c : oldTiles) tiles.insert(c);
    }

    //Compare against the new tiles
    while (!offsets.isEmpty()) {
        qint64 offset = offsets.pop();
        assert(this->outputFile->seek(offset));
        QByteArray newTiles = this->outputFile->read(tileOrderSize);
        assert(newTiles.size() == tileOrderSize);
        for (char c : newTiles) {
            if (!tiles.contains(c)) return true;
        }
    }
    return false;
}

QString Graphics_Ripper::Get_Base_Name_From_Path(const QString &path) {
    QString baseName;
    QStringList strings = QFileInfo(path).fileName().split('.');
    strings.removeLast();
    for (int i = 0; i < strings.size()-1; ++i) {
        baseName += strings.at(i) + ".";
    }
    baseName += strings.last();
    return baseName;
}

bool Graphics_Ripper::Is_Tile_Blank(char tileID, bool sprite) {
    QByteArray graphicsBytes;
    if (sprite) assert(this->Read_Graphics_Bytes_From_Sprite_Tile_ID(tileID, graphicsBytes));
    else assert(this->Read_Graphics_Bytes_From_Background_Tile_ID(tileID, graphicsBytes));
    for (int i = 0; i < graphicsBytes.size(); ++i) {
        if (graphicsBytes.at(i) != static_cast<char>(0x00)) return false;
    }
    return true;
}

bool Graphics_Ripper::Read_Graphics_Bytes_From_Sprite_Tile_ID(char tileID, QByteArray &graphicsBytes) {
    unsigned char c = static_cast<unsigned char>(tileID);
    qint64 spriteGraphicsOffset = 0x8010+(c*0x10); //get the graphics offset for the tile
    if (!this->outputFile->seek(spriteGraphicsOffset)) return false;
    graphicsBytes = this->outputFile->read(16);
    return graphicsBytes.size() == 16;
}

bool Graphics_Ripper::Read_Graphics_Bytes_From_Background_Tile_ID(char tileID, QByteArray &graphicsBytes) {
    unsigned char c = static_cast<unsigned char>(tileID);
    qint64 spriteGraphicsOffset = 0x9010+(c*0x10); //get the graphics offset for the tile
    if (!this->outputFile->seek(spriteGraphicsOffset)) return false;
    graphicsBytes = this->outputFile->read(16);
    return graphicsBytes.size() == 16;
}

bool Graphics_Ripper::Recreate_Working_File() {
    //Open the original file
    if (!this->originalFile) {
        this->originalFile = new QFile(originalFileLocation);
        if (!this->originalFile->open(QIODevice::ReadWrite)) { this->Close_Working_Files(); return false; }
    }

    //Create the base file if necessary
    QByteArray buffer(static_cast<int>(this->originalFile->size()), static_cast<char>(0x52));
    if (!this->baseFile) {
        this->baseFileLocation = this->applicationLocation+"/"+this->Get_Base_Name_From_Path(this->patchFileLocation)+"_base.nes";
        if (QFileInfo(this->baseFileLocation).exists()) QFile(this->baseFileLocation).remove();
        this->baseFile = new QFile(this->baseFileLocation);
        if (!this->baseFile->open(QIODevice::ReadWrite)) { this->Close_Working_Files(); return false; }
        if (this->baseFile->write(buffer) != buffer.size()) return false;
        if (!this->baseFile->reset()) return false;
    }

    //Delete the old working file if it exists
    this->writtenSpriteTiles.clear();
    this->writtenBackgroundTiles.clear();
    if (this->workingFile) {
        this->workingFile->close();
        this->workingFile->remove();
        delete this->workingFile;
        this->workingFile = nullptr;
    }

    //Create a copy of the original file to work with
    this->workingFileLocation = this->applicationLocation+"/"+this->Get_Base_Name_From_Path(this->patchFileLocation)+"_working.nes";
    if (QFileInfo(this->workingFileLocation).exists()) QFile(this->workingFileLocation).remove();
    this->workingFile = new QFile(this->workingFileLocation);
    if (!this->workingFile->open(QIODevice::ReadWrite)) { this->Close_Working_Files(); return false; }
    if (this->workingFile->write(buffer) != buffer.size()) return false;
    if (!this->workingFile->reset()) return false;
    return true;
}

bool Graphics_Ripper::Scan_For_Palette_Allowed() {
    QFile patchFile(this->patchFileLocation);
    if (!patchFile.open(QIODevice::ReadOnly)) return false;
    QTextStream stream(&patchFile);
    QString line = stream.readLine();
    bool done = false;
    while (!stream.atEnd() && !done) {
        if (line.startsWith(Patch_Strings::STRING_OFFSET)) {
            this->palettesDisabled = false;
            done = true;
        } else if (line.startsWith(Fix_Strings::STRING_ALLOW_PALETTES)) {
            this->palettesDisabled = true;
            done = true;
        } else if (line.startsWith(Fix_Strings::STRING_ALLOW_ONLY_COIN_PALETTES)) {
            this->palettesDisabled = true;
            done = true;
        }
    }
    patchFile.close();
    return true;
}

bool Graphics_Ripper::Write_Background_Tiles_To_Working_File(const QByteArray &tiles) {
    return this->Write_Tiles_To_Working_File(tiles, false);
}

bool Graphics_Ripper::Write_Sprite_Tiles_To_Working_File(const QByteArray &tiles) {
    return this->Write_Tiles_To_Working_File(tiles, true);
}

bool Graphics_Ripper::Write_Data_To_Working_File(qint64 offset, int amount) {
    if (!this->outputFile->seek(offset)) return false;
    QByteArray bytes = this->outputFile->read(amount);
    if (bytes.size() != amount) return false;
    if (!this->workingFile->seek(offset)) return false;
    return this->workingFile->write(bytes) == bytes.size();
}

bool Graphics_Ripper::Write_Tiles_And_Order_To_Working_File(qint64 offset, bool sprite, bool mario) {
    QStack<qint64> offsets;
    offsets.push(offset);
    return this->Write_Tiles_And_Order_To_Working_File(offsets, sprite, mario);
}

bool Graphics_Ripper::Write_Tiles_And_Order_To_Working_File(QStack<qint64> offsets, bool sprite, bool mario) {
    int tileOrderSize = 4;
    if (sprite) tileOrderSize = 6;
    if (mario) { assert(sprite); tileOrderSize = 8; }
    while (!offsets.isEmpty()) {
        qint64 offset = offsets.pop();
        //Read the tile order
        if (!this->outputFile->seek(offset)) return false;
        QByteArray tileOrder = this->outputFile->read(tileOrderSize);
        if (tileOrder.size() != tileOrderSize) return false;

        //Update blank tiles
        for (int i = 0; i < tileOrder.size(); ++i) {
            if (this->Is_Tile_Blank(tileOrder.at(i), sprite)) {
                if (sprite) tileOrder.data()[i] = static_cast<char>(0xFC);
                else tileOrder.data()[i] = static_cast<char>(0x24);
            }
        }

        //Write the tile order
        if (!this->workingFile->seek(offset)) return false;
        if (this->workingFile->write(tileOrder) != tileOrder.size()) return false;

        //Write the tiles themselves
        if (sprite) {
            if (!this->Write_Sprite_Tiles_To_Working_File(tileOrder)) return false;
        } else {
            if (!this->Write_Background_Tiles_To_Working_File(tileOrder)) return false;
        }
    }
    return true;
}

bool Graphics_Ripper::Write_Tiles_To_Working_File(const QByteArray &tiles, bool sprite) {
    for (char tile : tiles) {
        //Don't write the tile if it has already been written
        if (sprite) {
            if (this->writtenSpriteTiles.contains(tile)) continue;
        } else {
            if (this->writtenBackgroundTiles.contains(tile)) continue;
        }
        QByteArray graphicsBytes;
        qint64 offset = 0;
        if (sprite) {
            this->Read_Graphics_Bytes_From_Sprite_Tile_ID(tile, graphicsBytes);
            offset = 0x8010+(static_cast<unsigned char>(tile)*0x10);
        } else {
            this->Read_Graphics_Bytes_From_Background_Tile_ID(tile, graphicsBytes);
            offset = 0x9010+(static_cast<unsigned char>(tile)*0x10);
        }
        if (!this->workingFile->seek(offset)) return false;
        if (this->workingFile->write(graphicsBytes) != graphicsBytes.size()) return false;
        if (sprite) this->writtenSpriteTiles.insert(tile);
        else this->writtenBackgroundTiles.insert(tile);
    }
    return true;
}
