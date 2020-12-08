#include "command_factory.h"

//-----------------------------------------------------------------------------
// createCommand
// creates the different types of commands 
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

    // borrow type
    case CommandType::BorrowType:
        newCommand = createBorrow(infile);
        break;
    
    // return type
    case CommandType::ReturnType:
        newCommand = createReturn(infile);
        break;
    
    // history type
    case CommandType::HistoryType:
        newCommand = createHistory(infile);
        break;

    // inventory type
    case CommandType::InventoryType:
        newCommand = createInventory(infile);
        break;

    // error types
    default:       
        errorType(commandType, infile);
        break;
    }

    // return pointer of command
    return newCommand;
}

//-----------------------------------------------------------------------------
// createBorrow
// creates the borrow object
Command * CommandFactory::createBorrow(ifstream& infile) {

    // create a borrow
    Borrow * cBorrow = new Borrow();
    cBorrow->setCommandType(CommandType::BorrowType);
    if (cBorrow->setData(infile)) {
        return cBorrow;
    }
    delete cBorrow;
    return nullptr;
}

//-----------------------------------------------------------------------------
// createReturn
// creates the return object
Command * CommandFactory::createReturn(ifstream& infile) {

    Return* cReturn = new Return();
    cReturn->setCommandType(CommandType::ReturnType);
    if (cReturn->setData(infile)) {
        return cReturn;
    }
    delete cReturn;
    return nullptr;
}

//-----------------------------------------------------------------------------
// createHistory
// creates the history object
Command * CommandFactory::createHistory(ifstream& infile) {
    History* cHistory = new History();
    cHistory->setCommandType(CommandType::HistoryType);
    if (cHistory->setData(infile)) {
        return cHistory;
    }
    delete cHistory;
    return nullptr;
}

//------------------------------------------------------------------------------
// createInventory
// creates the inventory object
Command * CommandFactory::createInventory(ifstream& infile) {
    Inventory* cInventory = new Inventory();
    return cInventory;
}

//-----------------------------------------------------------------------------
// errorType
// show error of error type
void CommandFactory::errorType(const char& cType, ifstream& infile) {
    string fullCommand;
    getline(infile, fullCommand, '\n');
    cerr << "Command, invalid command type '" << cType << "':"
        << '\n' << "  " << cType << fullCommand << endl;
}