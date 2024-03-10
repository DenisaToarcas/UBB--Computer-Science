package model.adts;

import exception.MyException;
import javafx.util.Pair;
import model.statements.IStmt;

import java.util.HashMap;
import java.util.List;

public interface MyIProcTable {
    void add(String key, Pair<List<String>, IStmt> value);
    Pair<List<String>, IStmt> getValue(String key) throws MyException;
    boolean isDefined(String key);
    void update(String key, Pair<List<String>, IStmt> newValue) throws MyException;
    HashMap<String, Pair<List<String>, IStmt>> getContent();
}
