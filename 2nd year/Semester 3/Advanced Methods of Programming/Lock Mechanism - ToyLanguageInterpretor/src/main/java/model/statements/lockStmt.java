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

public class lockStmt implements IStmt{
    private final String var;
    private static final Lock lock = new ReentrantLock();

    public lockStmt(String var)
    {
        this.var = var;
    }

    @Override
    public String toString()
    {
        return "lock(" + this.var + ")";
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        lock.lock();

        MyIDictionary<String, Value> symTbl = state.getSymTable();
        MyILock lockTable = state.getLock();

        if (symTbl.isDefined(var))
        {
            if (symTbl.lookup(var).getType().equals(new IntType()))
            {
                int foundIndex = ((IntValue) symTbl.lookup(var)).getVal();
                if (lockTable.isDefined(foundIndex))
                {
                    if (lockTable.getValue(foundIndex) == -1)
                        lockTable.update(foundIndex, state.getPrgStateID());
                    else
                        state.getStk().push(this);
                }
                else
                    throw new MyException("lock: foundIndex not defined in the lockTable!");
            }
            else
                throw new MyException("lock: var is not of type Int!");
        }
        else
            throw new MyException("lock: var not defined in the symTbl!");

        lock.unlock();
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        Type type = typeEnv.lookup(var);
        if (type.equals(new IntType()))
            return typeEnv;
        else
            throw new MyException("lock: The var has not type Int!");
    }

    @Override
    public IStmt deepCopy() {
        return new lockStmt(this.var);
    }
}
