package model.statements;

import exception.MyException;
import model.adts.MyDictionary;
import model.adts.MyIDictionary;
import model.adts.MyIStack;
import model.adts.MyStack;
import model.prgState.PrgState;
import model.types.Type;
import model.values.Value;

import java.util.Map;

public class ForkStmt implements IStmt{

    private final IStmt stmt;

    public ForkStmt(IStmt stmt)
    {
        this.stmt = stmt;
    }

    @Override
    public String toString()
    {
        return "fork(" + this.stmt.toString() + ")";
    }

    @Override
    public PrgState execute(PrgState state) throws Exception
    {
        MyIStack<IStmt> newStack = new MyStack<IStmt>();
        MyIStack<MyIDictionary<String, Value>> newSymTbl = state.getAllSymTbl();

        return new PrgState(newStack, newSymTbl, state.getOut(), state.getFileTable(), state.getHeap(), state.getProcTable(), stmt);
    }

    @Override
    public IStmt deepCopy()
    {
        return new ForkStmt(this.stmt.deepCopy());
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String,Type> typeEnv) throws MyException
    {
        this.stmt.typeCheck(typeEnv);

        return typeEnv;
    }
}
