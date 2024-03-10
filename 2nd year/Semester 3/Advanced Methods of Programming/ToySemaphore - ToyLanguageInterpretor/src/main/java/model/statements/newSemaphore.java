package model.statements;

import exception.MyException;
import model.adts.MyIDictionary;
import model.adts.MyIHeap;
import model.adts.MyISemaphore;
import model.adts.Tuple;
import model.expressions.Exp;
import model.prgState.PrgState;
import model.types.IntType;
import model.types.Type;
import model.values.IntValue;
import model.values.Value;

import java.util.ArrayList;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class newSemaphore implements IStmt{
    private final String var;
    private final Exp exp1;
    private final Exp exp2;
    private static final Lock lock = new ReentrantLock();

    public newSemaphore(String var, Exp exp1, Exp exp2)
    {
        this.var = var;
        this.exp1 = exp1;
        this.exp2 = exp2;
    }

    @Override
    public String toString()
    {
        return "newSemaphore(" + this.var + ", " + this.exp1.toString() + ", " + this.exp2.toString() + ")";
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        lock.lock();

        MyIDictionary<String, Value> symTbl = state.getSymTable();
        MyIHeap<Integer, Value> heap = state.getHeap();
        MyISemaphore toySemaphore = state.getSemaphore();

        IntValue n1 = (IntValue) this.exp1.eval(symTbl, heap);
        IntValue n2 = (IntValue) this.exp2.eval(symTbl, heap);

        int number1 = n1.getVal();
        int number2 = n2.getVal();
        int freeAddress = toySemaphore.getFreeAddress();
        toySemaphore.add(freeAddress, new Tuple<>(number1, new ArrayList<>(), number2));

        if (symTbl.isDefined(var) && symTbl.getValue(var).getType().equals(new IntType()))
            symTbl.update(var, new IntValue(freeAddress));
        else
            throw new MyException("Semaphore: The var is not defined in the symTbl!");

        lock.unlock();

        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        return typeEnv;
    }

    @Override
    public IStmt deepCopy() {
        return new newSemaphore(this.var, this.exp1.deepCopy(), this.exp2.deepCopy());
    }
}
