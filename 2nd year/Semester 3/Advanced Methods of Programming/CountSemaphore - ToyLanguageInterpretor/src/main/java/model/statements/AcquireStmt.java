package model.statements;

import exception.MyException;
import model.adts.MyIDictionary;
import model.adts.MyISemaphore;
import model.adts.Pair;
import model.prgState.PrgState;
import model.types.IntType;
import model.types.Type;
import model.values.IntValue;
import model.values.Value;

import java.util.List;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class AcquireStmt implements IStmt{
    private final String var;
    private static final Lock lock = new ReentrantLock();

    public AcquireStmt(String var)
    {
        this.var = var;
    }

    @Override
    public String toString()
    {
        return "acquire(" + this.var + ")";
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        lock.lock();
        MyIDictionary<String, Value> symTbl = state.getSymTable();
        MyISemaphore toySemaphore = state.getSemaphore();
        if (symTbl.isDefined(var))
        {
            Type type = symTbl.getValue(var).getType();
            if (type.equals(new IntType()))
            {
                IntValue found = (IntValue) symTbl.lookup(var);
                 int foundIndex = found.getVal();

                 if (toySemaphore.isDefined(foundIndex))
                 {
                     Pair<Integer, List<Integer>> value = toySemaphore.getValue(foundIndex);
                     int lengthList = value.getSecond().size();
                     if (value.getFirst() > lengthList)
                     {
                         if (!value.getSecond().contains(state.getPrgStateID()))
                         {
                             value.getSecond().add(state.getPrgStateID());
                             toySemaphore.update(foundIndex, new Pair<>(value.getFirst(), value.getSecond()));
                         }
                     }
                     else
                         state.getStk().push(this);
                 }
                 else
                     throw new MyException("Acquire: foundIndex is not defined in the Semaphore!");
            }
            else
                throw new MyException("Acquire: Variable is not of type IntType!");
        }
        else
            throw new MyException("Acquire: Variable not defined in the SymTbl!");
        lock.unlock();
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        Type type = typeEnv.lookup(var);

        if (type.equals(new IntType()))
            return typeEnv;
        else
            throw new MyException("Type of the variable is not Int!");
    }

    @Override
    public IStmt deepCopy() {
        return new AcquireStmt(this.var);
    }
}
