package model.statements;

import exception.MyException;
import model.adts.MyIDictionary;
import model.expressions.Exp;
import model.prgState.PrgState;
import model.types.Type;
import model.values.Value;
public class AssignStmt implements IStmt {
    private final String id;
    private final Exp exp;

    public AssignStmt(String id, Exp exp)
    {
        this.id = id;
        this.exp = exp;
    }

    @Override
    public String toString(){
        return id + "=" + exp.toString();
    }
    @Override
    public PrgState execute(PrgState state) throws MyException{
        MyIDictionary<String,Value> symTbl= state.getSymTable();

        if (symTbl.isDefined(id)) {
            Value val = exp.eval(symTbl, state.getHeap());
            Type typId = (symTbl.lookup(id)).getType();

            if ((val.getType()).equals(typId))
                symTbl.update(id, val);
            else
                throw new MyException("declared type of variable " + id + " and type of the assigned expression do not match");
        }
        else throw new MyException("the used variable " +id + " was not declared before");

        return null;
    }

    @Override
    public IStmt deepCopy()
    {
        return new AssignStmt(this.id, this.exp.deepCopy());
    }

    @Override
    public MyIDictionary<String,Type> typeCheck(MyIDictionary<String,Type> typeEnv) throws MyException{
        Type typevar = typeEnv.lookup(id);
        Type typexp = exp.typeCheck(typeEnv);

        if (typevar.equals(typexp))
            return typeEnv;
        else
            throw new MyException("Assignment: right hand side and left hand side have different types ");
    }
    }
