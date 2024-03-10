package model.statements;

import exception.MyException;
import model.adts.MyIDictionary;
import model.adts.MyIHeap;
import model.adts.MyILatchTable;
import model.expressions.Exp;
import model.prgState.PrgState;
import model.types.IntType;
import model.types.Type;
import model.values.IntValue;
import model.values.Value;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class newLatchStmt implements IStmt{
    private final String var;
    private final Exp exp;

    private static final Lock lock = new ReentrantLock();

    public newLatchStmt(String var, Exp exp)
    {
        this.var = var;
        this.exp = exp;
    }

    @Override
    public String toString()
    {
        return "newLatch(" + this.var + ", " + this.exp.toString() + ")";
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        lock.lock();
        MyIDictionary<String, Value> symTbl = state.getSymTable();
        MyIHeap<Integer, Value> heap = state.getHeap();
        MyILatchTable latchTable = state.getLatchTable();

        Value value =  this.exp.eval(symTbl, heap);
        if (value.getType().equals(new IntType()))
        {
            IntValue num = (IntValue) value;
            int num1 = num.getVal();

            int freeAddress = latchTable.getFreeAddress();
            latchTable.add(freeAddress, num1);
            if (symTbl.isDefined(var))
            {
                Type type = symTbl.lookup(var).getType();
                if (type.equals(new IntType()))
                {
                    symTbl.update(var, new IntValue(freeAddress));
                }
                else
                    throw new MyException("newLatch: Var is not of type int!");
            }
            else
                throw new MyException("newLatch: The var is not defined in the SymTbl!");
        }
        else
            throw new MyException("newLatch: The type of the evaluated exp is not IntType!");
        lock.unlock();;
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        if (typeEnv.lookup(var).equals(new IntType()))
        {
            if (exp.typeCheck(typeEnv).equals(new IntType()))
                return typeEnv;
            else
                throw new MyException("The expression is not of type Int!");
        }
        else
            throw new MyException("The variable is not of type Int!");
    }

    @Override
    public IStmt deepCopy() {
        return new newLatchStmt(this.var, this.exp.deepCopy());
    }
}
