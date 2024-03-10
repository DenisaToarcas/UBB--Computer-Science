package model.statements;

import exception.MyException;
import model.adts.MyIDictionary;
import model.prgState.PrgState;
import model.types.Type;

public class ReturnStmt implements IStmt{

    @Override
    public String toString()
    {
        return "Return";
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        state.getAllSymTbl().pop();
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        return typeEnv;
    }

    @Override
    public IStmt deepCopy() {
        return new ReturnStmt();
    }
}
