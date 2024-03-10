package model.statements;

import exception.MyException;
import model.adts.MyIDictionary;
import model.adts.MyILatchTable;
import model.prgState.PrgState;
import model.types.IntType;
import model.types.Type;
import model.values.IntValue;
import model.values.Value;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class AwaitStmt implements IStmt{
    private final String var;
    private static final Lock lock = new ReentrantLock();

    public AwaitStmt(String var)
    {
        this.var = var;
    }

    @Override
    public String toString()
    {
        return "await(" + this.var + ")";
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        lock.lock();
        MyIDictionary<String, Value> symTbl = state.getSymTable();
        MyILatchTable latchTbl = state.getLatchTable();

        if (symTbl.isDefined(var))
        {
            Type type = symTbl.lookup(var).getType();
            if (type.equals(new IntType()))
            {
                int foundIndex = ((IntValue) symTbl.lookup(var)).getVal();
                if (latchTbl.isDefined(foundIndex))
                {
                    if (latchTbl.getValue(foundIndex) != 0)
                        state.getStk().push(this);
                }
                else
                    throw new MyException("await: The foundIndex is not defined in the latchTable!");
            }
            else
                throw new MyException("await: Variable has not type IntType in SymTbl!");
        }
        else
            throw new MyException("await: Variable not defined in the symTbl!");
        lock.unlock();

        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        if (typeEnv.lookup(var).equals(new IntType()))
            return typeEnv;
        else
            throw new MyException("The variable is not of type Int!");
    }

    @Override
    public IStmt deepCopy() {
        return new AwaitStmt(this.var);
    }
}
