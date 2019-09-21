#ifndef ENEMY_PARSER_H
#define ENEMY_PARSER_H

#include "../../../Level-Headed/SMB1/SMB1_Compliance_Generator/SMB1_Compliance_Generator_Arguments.h"
#include <QTextStream>

class Coordinates;
class Enemy_Writer;
class Object_Writer;
class Pipe_Pointer_Writer;

class Enemy_Parser {
public:
    Enemy_Parser(QTextStream *s, int numBytesLeft, SMB1_Compliance_Generator_Arguments *args);
    ~Enemy_Parser();
    bool At_End(char coordinates);
    bool Is_Pipe_Pointer(char coordinates, char enemy);
    bool Parse_Enemy(char coordinates, char enemy);
    bool Parse_Pipe_Pointer(char coordinates, char levelSlot, char page);

private:
    Coordinates *coordinates;
    Enemy_Writer *enemyWriter;
    Object_Writer *objectWriter;
    Pipe_Pointer_Writer *pipePointerWriter;
    SMB1_Compliance_Generator_Arguments *args;
};

#endif // ENEMY_PARSER_H
