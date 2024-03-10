package model.statements;

import exception.MyException;
import model.adts.MyIDictionary;
import model.adts.MyILock;
import model.prgState.PrgState;
import model.types.IntType;
import model.types.Type;
import model.values.IntValue;
import model.values.Value;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class newLockStmt implements IStmt{
    private final String var;
    private static final Lock lock = new ReentrantLock();

    public newLockStmt(String var)
    {
        this.var = var;
    }

    @Override
    public String toString()
    {
        return "newLock(" + this.var + ")";
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        lock.lock();

        MyIDictionary<String, Value> symTbl = state.getSymTable();
        MyILock lockTable = state.getLock();

        int freeLocation = lockTable.getFreeAddress();
        lockTable.add(freeLocation, -1);
        if (symTbl.isDefined(var))
        {
            if (symTbl.lookup(var).getType().equals(new IntType()))
                symTbl.update(var, new IntValue(freeLocation));
            else
                throw new MyException("newLock: The var has not type Int in the SymTbl!");
        }
        else
            throw new MyException("newLock: The var is not defined in the SymTbl!");

        lock.unlock();
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        Type type = typeEnv.lookup(var);
        if (type.equals(new IntType()))
            return typeEnv;
        else
            throw new MyException("newLock: The var has not type Int!");
    }

    @Override
    public IStmt deepCopy() {
        return new newLockStmt(this.var);
    }
}
