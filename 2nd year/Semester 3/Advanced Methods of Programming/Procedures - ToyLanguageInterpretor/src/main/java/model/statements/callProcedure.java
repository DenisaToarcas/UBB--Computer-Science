package model.statements;

import exception.MyException;
import model.adts.MyDictionary;
import model.adts.MyIDictionary;
import model.adts.MyIProcTable;
import model.expressions.Exp;
import model.prgState.PrgState;
import model.types.Type;
import model.values.Value;

import java.util.List;

public class callProcedure implements IStmt{
    private final String procedureName;
    private final List<Exp> expressions;

    public callProcedure(String procedureName, List<Exp> expressions)
    {
        this.procedureName = procedureName;
        this.expressions = expressions;
    }

    @Override
    public String toString()
    {
        return "call " + this.procedureName + " (" + this.expressions.toString() + ")";
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        MyIDictionary<String, Value> symTbl = state.getSymTable();
        MyIProcTable procTbl = state.getProcTable();

        if (procTbl.isDefined(this.procedureName))
        {
            List<String> variables = procTbl.getValue(this.procedureName).getKey();
            IStmt statement = procTbl.getValue(this.procedureName).getValue();
            MyIDictionary<String, Value> newSymTbl = new MyDictionary<>();

            for (String var: variables)
            {
                int index = variables.indexOf(var);
                newSymTbl.add(var, expressions.get(index).eval(symTbl, state.getHeap()));
            }
            state.getAllSymTbl().push(newSymTbl);
            state.getStk().push(new ReturnStmt());
            state.getStk().push(statement);
        }
        else
            throw new MyException("call: The procedure name is not defined in the procTable!");
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        return typeEnv;
    }

    @Override
    public IStmt deepCopy() {
        return new callProcedure(this.procedureName, this.expressions);
    }
}
