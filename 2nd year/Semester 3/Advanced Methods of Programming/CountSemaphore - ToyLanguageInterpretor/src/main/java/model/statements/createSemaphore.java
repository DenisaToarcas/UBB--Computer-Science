package model.statements;

import exception.MyException;
import model.adts.MyIDictionary;
import model.adts.MyIHeap;
import model.adts.MyISemaphore;
import model.adts.Pair;
import model.expressions.Exp;
import model.prgState.PrgState;
import model.types.IntType;
import model.types.Type;
import model.values.IntValue;
import model.values.Value;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class createSemaphore implements IStmt{
    private final String var;
    private final Exp exp1;
    private static final Lock lock = new ReentrantLock();

    public createSemaphore(String var, Exp exp1)
    {
        this.var = var;
        this.exp1 = exp1;
    }

    @Override
    public String toString()
    {
        return "createSemaphore(" + this.var + ", " + this.exp1.toString() + ")";
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        lock.lock();

        MyIDictionary<String, Value> symTbl = state.getSymTable();
        MyIHeap<Integer, Value> heap = state.getHeap();
        MyISemaphore toySemaphore = state.getSemaphore();

        IntValue n1 = (IntValue) this.exp1.eval(symTbl, heap);

        int number1 = n1.getVal();
        int freeAddress = toySemaphore.getFreeAddress();
        toySemaphore.add(freeAddress, new Pair<>(number1, new ArrayList<>()));

        if (symTbl.isDefined(var) && symTbl.getValue(var).getType().equals(new IntType()))
            symTbl.update(var, new IntValue(freeAddress));
        else
            throw new MyException("Semaphore: The var is not defined in the symTbl!");

        lock.unlock();

        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        Type type = typeEnv.lookup(var);

        if (type.equals(new IntType()))
        {
            if (exp1.typeCheck(typeEnv).equals(new IntType()))
                return typeEnv;
            else
                throw new MyException("The expression does not evaluate to Int!");
        }
        else
            throw new MyException("Type of the variable is not Int!");
    }

    @Override
    public IStmt deepCopy() {
        return new createSemaphore(this.var, this.exp1.deepCopy());
    }
}
