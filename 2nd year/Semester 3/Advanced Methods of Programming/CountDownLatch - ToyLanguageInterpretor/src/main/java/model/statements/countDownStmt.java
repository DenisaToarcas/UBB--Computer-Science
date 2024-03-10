package model.statements;

import exception.MyException;
import model.adts.MyIDictionary;
import model.adts.MyILatchTable;
import model.expressions.ValueExp;
import model.prgState.PrgState;
import model.types.IntType;
import model.types.Type;
import model.values.IntValue;
import model.values.Value;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class countDownStmt implements IStmt{

    private final String var;
    private static final Lock lock = new ReentrantLock();

    public countDownStmt(String var)
    {
        this.var = var;
    }

    @Override
    public String toString()
    {
        return "countDown(" + this.var + ")";
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
                    if (latchTbl.getValue(foundIndex) > 0)
                    {
                        latchTbl.update(foundIndex, latchTbl.getValue(foundIndex)-1);
                        state.getStk().push(new PrintStmt(new ValueExp(new IntValue(state.getPrgStateID()))));
                    }
                    else
                        state.getStk().push(new PrintStmt(new ValueExp(new IntValue(state.getPrgStateID()))));
                }
                else
                    throw new MyException("countDown: The foundIndex is not defined in the latchTable!");
            }
            else
                throw new MyException("countDown: Variable has not type IntType in SymTbl!");
        }
        else
            throw new MyException("countDown: Variable not defined in the symTbl!");


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
        return new countDownStmt(this.var);
    }
}
