#include "command_factory.h"

Command * CommandFactory::createCommand(ifstream & infile) {
    Command * newCommand = nullptr;
    char commandType;
    infile >> commandType;

    // if fail to read movie type
    if (infile.fail()) {
        infile.clear();
        infile.ignore(99, '\n');
        return nullptr;
    }

    // specific type
    switch (commandType) {
    case BORROW:
        newCommand = createBorrow(infile);
        break;
    case RETURN:
        newCommand = createReturn(infile);
        break;
    case HISTORY:
        newCommand = createHistory(infile);
        break;
    case INVENTORY:
        newCommand = createInventory(infile);
        break;
    default:       
        errorType(commandType, infile);
        break;
    }

    // return pointer of command
    return newCommand;
}

Command * CommandFactory::createBorrow(ifstream& infile) {

    // create a borrow
    Borrow * cBorrow = new Borrow();
    cBorrow->setCommandType(BORROW);
    if (cBorrow->setData(infile)) {
        return cBorrow;
    }
    delete cBorrow;
    return nullptr;
}

Command * CommandFactory::createReturn(ifstream& infile) {

    Return* cReturn = new Return();
    cReturn->setCommandType(RETURN);
    if (cReturn->setData(infile)) {
        return cReturn;
    }
    delete cReturn;
    return nullptr;
}

Command * CommandFactory::createHistory(ifstream& infile) {
    History* cHistory = new History();
    cHistory->setCommandType(HISTORY);
    if (cHistory->setData(infile)) {
        return cHistory;
    }
    delete cHistory;
    return nullptr;
}

Command * CommandFactory::createInventory(ifstream& infile) {
    Inventory* cInventory = new Inventory();
    return cInventory;
}

void CommandFactory::errorType(const char& cType, ifstream& infile) {
    string fullCommand;
    getline(infile, fullCommand, '\n');
    cerr << "Command, invalid command type '" << cType << "':"
        << '\n' << "  " << cType << fullCommand << endl;
}
