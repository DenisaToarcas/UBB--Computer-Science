package org.example.CountDownLatch;

import controller.Controller;
import exception.MyException;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.layout.Region;
import javafx.util.Pair;
import model.adts.*;
import model.expressions.*;
import model.prgState.PrgState;
import model.statements.*;
import model.types.*;
import model.values.BoolValue;
import model.values.IntValue;
import model.values.StringValue;
import model.values.Value;

import java.io.BufferedReader;
import java.net.URL;
import java.util.*;

public class PrgStatesExecutionController implements Initializable {

    private int PrgStateIdentifierSelected = -1;
    private ObservableList<String> prgStateIdentifiers;
    private ArrayList<IStmt> stmts;
    private ArrayList<PrgState> prgStates;
    private Controller controller;

    private PrgState stateToExecute;
    private PrgState previousStateExecuted;
    //this I introduced for the out list to be updated, if the last
    //command is print

    //---------HEAP----------------------------
    @FXML
    private Label HeapLabel;

    @FXML
    private TableView<Pair<String, String>> HeapTableView;

    @FXML
    private TableColumn<Pair<String, String>, String> AddressTableColumn;

    @FXML
    private TableColumn<Pair<String, String>, String> ValueTableColumn;

    //---------OUT----------------------------
    @FXML
    private Label OutLabel;

    @FXML
    private ListView<String> OutListView;

    //---------SYM TABLE----------------------------
    @FXML
    private Label SymTableLabel;

    @FXML
    private TableView<Pair<String, String>> SymTableTableView;

    @FXML
    private TableColumn<Pair<String, String>, String> VariableNameTableColumn;

    @FXML
    private TableColumn<Pair<String, String>, String> ValueSymTblTableColumn;

    //---------EXE STACK----------------------------
    @FXML
    private Label ExeStackLabel;

    @FXML
    private ListView<String> ExeStackListView;

    //---------FILE TABLE----------------------------
    @FXML
    private Label FileTableLabel;

    @FXML
    private ListView<String> FileTableListView;

    //---------PRG STATES----------------------------

    @FXML
    private Label PrgStateIdentifiersLabel;

    @FXML
    private ListView<String> PrgStateIdentifiersListView;

    @FXML
    private Label NoOfPrgStatesLabel;

    @FXML
    private TextField NoOfPrgStatesTextField;

    @FXML
    private Button RunOneStepButton;

    @FXML
    private TableView<Pair<Integer, Integer>> CountDownLatchListView;

    @FXML
    private TableColumn<Pair<Integer, Integer>, Integer> latchLocationColumn;

    @FXML
    private TableColumn<Pair<Integer, Integer>, Integer> latchValueColumn;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {

        prgStateIdentifiers = FXCollections.observableArrayList();
        stmts = new ArrayList<>();
        prgStates = new ArrayList<>();

        addAllStatements();

        for (IStmt stmt: stmts)
        {
            MyIStack<IStmt> exeStack = new MyStack<IStmt>();
            MyIDictionary<String, Value> SymTbl = new MyDictionary<String, Value>();
            MyIList<Value> Out = new MyList<Value>();
            MyIHeap<Integer, Value> Heap = new Heap();
            MyIFileTable<String, BufferedReader> FileTable = new FileTable();
            MyIDictionary<String, Type> typeEnv = new MyDictionary<>();
            MyILatchTable latchTable = new MyLatchTable();

            try {
                stmt.typeCheck(typeEnv);
                PrgState prgState = new PrgState(exeStack, SymTbl, Out, FileTable, Heap, latchTable, stmt);

                this.prgStates.add(prgState);
                this.prgStateIdentifiers.add(String.valueOf(prgState.getPrgStateID()));

            } catch (MyException exception) {
                Alert alert = new Alert(Alert.AlertType.ERROR, exception.toString(), ButtonType.OK);
                alert.setTitle("Error Dialog!");
                alert.getDialogPane().setMinHeight(Region.USE_PREF_SIZE);
                alert.showAndWait();
            }
        }

        this.NoOfPrgStatesTextField.setText(String.valueOf(this.prgStates.size()));
        populatePrgStateIdentifiersListView();

        this.stateToExecute = null;

        AddressTableColumn.setCellValueFactory(p ->
        {
            return new SimpleStringProperty(p.getValue().getKey());
        });
        ValueTableColumn.setCellValueFactory(p ->
        {
            return new SimpleStringProperty(p.getValue().getValue());
        });
        VariableNameTableColumn.setCellValueFactory(p ->
        {
            return new SimpleStringProperty(p.getValue().getKey());
        });
        ValueSymTblTableColumn.setCellValueFactory(p ->
        {
            return new SimpleStringProperty(p.getValue().getValue());
        });

        latchLocationColumn.setCellValueFactory(p ->
        {
            return new SimpleIntegerProperty(p.getValue().getKey()).asObject();
        });
        latchValueColumn.setCellValueFactory(p ->
        {
            return new SimpleIntegerProperty(p.getValue().getValue()).asObject();
        });
    }

    public PrgState getPrg()
    {
        if (controller.getPrgStates().isEmpty())
            return null;
        else
        {
            return this.controller.getPrgStates().getFirst();
        }
    }

    public void OneStepButtonClicked()
    {
        if (this.controller == null)
        {
            Alert alert = new Alert(Alert.AlertType.ERROR, "PrgState was not selected from the other window!!!", ButtonType.OK);
            alert.setTitle("Error Dialog!");
            alert.getDialogPane().setMinHeight(Region.USE_PREF_SIZE);
            alert.showAndWait();
        }

        else {
            if (this.stateToExecute == null || this.stateToExecute.getStk().isEmpty()) {
                Alert alert = new Alert(Alert.AlertType.ERROR, "PrgState is null or the stack is empty!!!", ButtonType.OK);
                alert.setTitle("Error Dialog!");
                alert.getDialogPane().setMinHeight(Region.USE_PREF_SIZE);
                alert.showAndWait();
            }
            else
            {
                try
                {
                    this.previousStateExecuted = getPrg();
                    controller.wrapperFunctionforGUI();
                    this.stateToExecute = getPrg();

                }catch (MyException exception)
                {
                    Alert alert = new Alert(Alert.AlertType.ERROR, exception.toString(), ButtonType.OK);
                    alert.setTitle("Error Dialog!");
                    alert.getDialogPane().setMinHeight(Region.USE_PREF_SIZE);
                    alert.showAndWait();

                } catch (Exception e) {
                    Alert alert = new Alert(Alert.AlertType.ERROR, e.toString(), ButtonType.OK);
                    alert.setTitle("Error Dialog!");
                    alert.getDialogPane().setMinHeight(Region.USE_PREF_SIZE);
                    alert.showAndWait();
                }
            }
        }
        populateExeStackListView();
        populateOutListView();
        populateFileTableListView();
        populateSymTableTableView();
        populateHeapTableView();
        populateCountDownLatchTableView();
    }

    public void populateExeStackListView()
    {
        if (this.stateToExecute != null)
        {
            List<String> exeStack = this.stateToExecute.getStk().getToString();
            this.ExeStackListView.setItems(FXCollections.observableList(exeStack));
        }
        else
            this.ExeStackListView.setItems(null);
    }

    public void populateOutListView()
    {
        if (this.previousStateExecuted != null)
        {
            List<String> outList = Collections.singletonList(this.previousStateExecuted.getOut().toString());
            this.OutListView.setItems(FXCollections.observableList(outList));
        }
        else
            this.OutListView.setItems(null);
    }

    public void populateFileTableListView()
    {
        if (this.stateToExecute != null)
        {
            List<String> files = Collections.singletonList(this.stateToExecute.getFileTable().toString());
            this.FileTableListView.setItems(FXCollections.observableList(files));
        }
        else
            this.FileTableListView.setItems(null);
    }

    public void populateSymTableTableView()
    {
        List<Pair<String, String>> symTbl = new ArrayList<>();
        if (this.previousStateExecuted != null)
        {
            for (String key : this.previousStateExecuted.getSymTable().getContent().keySet())
            {
                symTbl.add(new Pair<>(key, this.previousStateExecuted.getSymTable().getValue(key).toString()));
            }
        }

        this.SymTableTableView.setItems(FXCollections.observableList(symTbl));
    }

    public void populateHeapTableView()
    {
        List<Pair<String, String>> heapTbl = new ArrayList<>();
        if (this.previousStateExecuted != null)
        {
            for (Integer key : this.previousStateExecuted.getHeap().getContent().keySet())
            {
                heapTbl.add(new Pair<>(key.toString(), this.previousStateExecuted.getHeap().getValue(key).toString()));
            }
        }

        this.HeapTableView.setItems(FXCollections.observableList(heapTbl));
    }

    public void populateCountDownLatchTableView()
    {
        PrgState programState = getPrg();
        MyILatchTable latchTable = Objects.requireNonNull(programState).getLatchTable();
        ArrayList<Pair<Integer, Integer>> latchTableEntries = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry: latchTable.getLatchTable().entrySet()) {
            latchTableEntries.add(new Pair<>(entry.getKey(), entry.getValue()));
        }
        CountDownLatchListView.setItems(FXCollections.observableArrayList(latchTableEntries));
    }

    public void populatePrgStateIdentifiersListView()
    {
        this.PrgStateIdentifiersListView.setItems(prgStateIdentifiers);
    }

    public void checkIfPrgStateIdentifierSelected()
    {
        this.PrgStateIdentifierSelected = PrgStateIdentifiersListView.getSelectionModel().getSelectedIndex();
        this.ExeStackListView.setItems(
                FXCollections.observableList(this.prgStates.get(PrgStateIdentifierSelected).getStk().getToString())
        );
    }

    public void setController(Controller contr)
    {
        this.controller = contr;
    }

    public void setPrgToExec(PrgState prgState)
    {
        this.stateToExecute = prgState;
    }

    public void addAllStatements()
    {
        IStmt ex1 = new CompStmt(new VarDeclStmt("v", new IntType()), new CompStmt(new AssignStmt("v", new ValueExp(new IntValue(2))), new PrintStmt(new VarExp("v"))));
        stmts.add(ex1);

        IStmt ex2 = new CompStmt(new VarDeclStmt("a", new IntType()),
                new CompStmt(new VarDeclStmt("b", new IntType()),
                        new CompStmt(new AssignStmt("a", new ArithExp("+", new ValueExp(new IntValue(2)), new
                                ArithExp("*", new ValueExp(new IntValue(3)), new ValueExp(new IntValue(5))))),
                                new CompStmt(new AssignStmt("b", new ArithExp("+", new VarExp("a"), new ValueExp(new
                                        IntValue(1)))), new PrintStmt(new VarExp("b"))))));
        stmts.add(ex2);

        IStmt ex3 = new CompStmt(new VarDeclStmt("a", new BoolType()),
                new CompStmt(new VarDeclStmt("v", new IntType()),
                        new CompStmt(new AssignStmt("a", new ValueExp(new BoolValue(true))),
                                new CompStmt(new IfStmt(new VarExp("a"), new AssignStmt("v", new ValueExp(new
                                        IntValue(2))), new AssignStmt("v", new ValueExp(new IntValue(3)))), new PrintStmt(new
                                        VarExp("v"))))));
        stmts.add(ex3);

        IStmt ex4 = new CompStmt(new VarDeclStmt("varf", new StringType()), new CompStmt(new AssignStmt("varf", new ValueExp(new StringValue("src/test.in"))), new CompStmt(new OpenRFile(new VarExp("varf")), new CompStmt(new VarDeclStmt("varc", new IntType()), new CompStmt(new ReadFile(new VarExp("varf"), "varc"), new CompStmt(new PrintStmt(new VarExp("varc")), new CloseRFile(new VarExp("varf"))))))));
        stmts.add(ex4);

        IStmt ex5 = new PrintStmt(new RelationalExp("==", new ValueExp(new IntValue(5)), new ValueExp(new IntValue(7))));
        stmts.add(ex5);

        IStmt ex6 = new CompStmt(new VarDeclStmt("v", new IntType()),
                new CompStmt(new AssignStmt("v", new ValueExp(new IntValue(5))),
                        new CompStmt(new WhileStmt(new RelationalExp(">", new VarExp("v"), new ValueExp(new IntValue(0))),
                                new CompStmt(new PrintStmt(new VarExp("v")), new AssignStmt("v", new ArithExp("-", new VarExp("v"), new ValueExp(new IntValue(1)))))), new NopStmt())));
        stmts.add(ex6);

        IStmt ex7 = new CompStmt(new VarDeclStmt("v", new RefType(new IntType())), new CompStmt(new aHStmt("v", new ValueExp(new IntValue(20))), new CompStmt(new VarDeclStmt("a", new RefType(new RefType(new IntType()))), new CompStmt(new aHStmt("a", new VarExp("v")), new CompStmt(new PrintStmt(new VarExp("v")), new PrintStmt(new VarExp("a")))))));
        stmts.add(ex7);

        IStmt ex8 = new CompStmt(new VarDeclStmt("v", new RefType(new IntType())), new CompStmt(new aHStmt("v", new ValueExp(new IntValue(20))), new CompStmt(new VarDeclStmt("a", new RefType(new RefType(new IntType()))), new CompStmt(new aHStmt("a", new VarExp("v")), new CompStmt(new PrintStmt(new rHExp(new VarExp("v"))), new PrintStmt(new ArithExp("+", new rHExp(new rHExp(new VarExp("a"))), new ValueExp(new IntValue(5)))))))));
        stmts.add(ex8);

        IStmt ex9 = new CompStmt(new VarDeclStmt("v", new RefType(new IntType())), new CompStmt(new aHStmt("v", new ValueExp(new IntValue(20))), new CompStmt(new PrintStmt(new rHExp(new VarExp("v"))), new CompStmt(new wHStmt("v", new ValueExp(new IntValue(30))), new PrintStmt(new ArithExp("+", new rHExp(new VarExp("v")), new ValueExp(new IntValue(5))))))));
        stmts.add(ex9);

        IStmt ex10 = new CompStmt(new VarDeclStmt("v", new RefType(new IntType())), new CompStmt(new aHStmt("v", new ValueExp(new IntValue(20))), new CompStmt(new VarDeclStmt("a", new RefType(new RefType(new IntType()))), new CompStmt(new aHStmt("a", new VarExp("v")), new CompStmt(new aHStmt("v", new ValueExp(new IntValue(30))), new PrintStmt(new rHExp(new rHExp(new VarExp("a")))))))));
        stmts.add(ex10);

        IStmt ex11 = new CompStmt(new VarDeclStmt("v", new RefType(new IntType())), new CompStmt(new aHStmt("v", new ValueExp(new IntValue(20))), new aHStmt("v", new ValueExp(new IntValue(30)))));
        stmts.add(ex11);

        IStmt ex12 = new CompStmt(
                new VarDeclStmt("v", new IntType()), new CompStmt(
                new VarDeclStmt("a", new RefType(new IntType())), new CompStmt(
                new AssignStmt("v", new ValueExp(new IntValue(10))), new CompStmt(
                new aHStmt("a", new ValueExp(new IntValue(22))), new CompStmt(
                new ForkStmt(new CompStmt(new wHStmt("a", new ValueExp(new IntValue(30))), new CompStmt(
                        new AssignStmt("v", new ValueExp(new IntValue(32))), new CompStmt(
                        new PrintStmt(new VarExp("v")),
                        new PrintStmt(new rHExp(new VarExp("a"))))))), new CompStmt(new PrintStmt(new VarExp("v")), new PrintStmt(new rHExp(new VarExp("a")))))))));
        stmts.add(ex12);

        IStmt ex13 = new CompStmt(
                new VarDeclStmt("a", new RefType(new IntType())), new CompStmt(
                new VarDeclStmt("counter", new IntType()),
                new WhileStmt(new RelationalExp("<", new VarExp("counter"), new ValueExp(new IntValue(10))),
                        new CompStmt(new ForkStmt(new ForkStmt(new CompStmt(new aHStmt("a", new VarExp("counter")), new CompStmt(new PrintStmt(new VarExp("counter")), new PrintStmt(new rHExp(new VarExp("a"))))))),
                                new AssignStmt("counter", new ArithExp("+", new VarExp("counter"), new ValueExp(new IntValue(1))))))));
        stmts.add(ex13);

        IStmt ex14 = new CompStmt(new VarDeclStmt("v", new IntType()),
                new CompStmt(new ConditionalAssignment("v", new RelationalExp("==", new ValueExp(new IntValue(5)), new ValueExp(new IntValue(5))),
                        new ValueExp(new IntValue(10)),
                        new ValueExp(new IntValue(15))), new PrintStmt(new VarExp("v"))));
        stmts.add(ex14);

        //CONDITIONAL ASSIGNMENT
        IStmt ex15 = new CompStmt(new VarDeclStmt("b", new BoolType()),
                new CompStmt(new VarDeclStmt("c", new IntType()),
                        new CompStmt(new AssignStmt("b", new ValueExp(new BoolValue(true))),
                                new CompStmt(new ConditionalAssignment("c", new VarExp("b"), new ValueExp(new IntValue(100)), new ValueExp(new IntValue(200))),
                                        new CompStmt(new PrintStmt(new VarExp("c")),
                                                new CompStmt(new ConditionalAssignment("c", new ValueExp(new BoolValue(false)), new ValueExp(new IntValue(100)), new ValueExp(new IntValue(200))), new PrintStmt(new VarExp("c"))))))));
        stmts.add(ex15);

        //FOR STATEMENT
        IStmt ex16 = new CompStmt(new VarDeclStmt("a", new RefType(new IntType())),
                new CompStmt(new aHStmt("a", new ValueExp(new IntValue(20))),
                        new CompStmt(new ForStmt("v", new ValueExp(new IntValue(0)), new ValueExp(new IntValue(3)), new ArithExp("+", new VarExp("v"), new ValueExp(new IntValue(1))), new ForkStmt(new CompStmt(new PrintStmt(new VarExp("v")), new AssignStmt("v", new ArithExp("*", new VarExp("v"), new rHExp(new VarExp("a")))))
                        )), new PrintStmt(new rHExp(new VarExp("a"))))));
        stmts.add(ex16);

        //CONDITIONAL ASSIGNMENT
        IStmt ex17 = new CompStmt(new VarDeclStmt("a", new RefType(new IntType())),
                new CompStmt(new VarDeclStmt("b", new RefType(new IntType())),
                        new CompStmt(new VarDeclStmt("v", new IntType()),
                                new CompStmt(new aHStmt("a", new ValueExp(new IntValue(0))),
                                        new CompStmt(new aHStmt("b", new ValueExp(new IntValue(0))),
                                                new CompStmt(new wHStmt("a", new ValueExp(new IntValue(1))),
                                                        new CompStmt(new wHStmt("b", new ValueExp(new IntValue(2))),
                                                                new CompStmt(new ConditionalAssignment("v", new RelationalExp("<", new rHExp(new VarExp("a")), new rHExp(new VarExp("b"))), new ValueExp(new IntValue(100)), new ValueExp(new IntValue(200))),
                                                                        new CompStmt(new PrintStmt(new VarExp("v")),
                                                                                new CompStmt(new ConditionalAssignment("v", new RelationalExp(">", new ArithExp("-", new rHExp(new VarExp("b")), new ValueExp(new IntValue(2))), new rHExp(new VarExp("a"))), new ValueExp(new IntValue(100)), new ValueExp(new IntValue(200))), new PrintStmt(new VarExp("v"))))))))))));
        stmts.add(ex17);

        //SWITCH STMT
        IStmt ex18 = new CompStmt(new VarDeclStmt("a", new IntType()),
                new CompStmt(new VarDeclStmt("b", new IntType()),
                        new CompStmt(new VarDeclStmt("c", new IntType()),
                                new CompStmt(new AssignStmt("a", new ValueExp(new IntValue(1))),
                                        new CompStmt(new AssignStmt("b", new ValueExp(new IntValue(2))),
                                                new CompStmt(new AssignStmt("c", new ValueExp(new IntValue(5))),
                                                        new CompStmt(new SwitchStmt(new ArithExp("*", new VarExp("a"), new ValueExp(new IntValue(10))),
                                                                new ArithExp("*", new VarExp("b"), new VarExp("c")), new CompStmt(new PrintStmt(new VarExp("a")), new PrintStmt(new VarExp("b"))),
                                                                new ValueExp(new IntValue(10)), new CompStmt(new PrintStmt(new ValueExp(new IntValue(100))), new PrintStmt(new ValueExp(new IntValue(200)))), new PrintStmt(new ValueExp(new IntValue(300)))), new PrintStmt(new ValueExp(new IntValue(300))))))))));
        stmts.add(ex18);

        //REPEAT UNTIL STMT
        IStmt ex19 = new CompStmt(new VarDeclStmt("v", new IntType()),
                new CompStmt(new AssignStmt("v", new ValueExp(new IntValue(0))),
                        new CompStmt(new RepeatUntil(new CompStmt(new ForkStmt(new CompStmt(new PrintStmt(new VarExp("v")), new AssignStmt("v", new ArithExp("+", new VarExp("v"), new ValueExp(new IntValue(1)))))), new AssignStmt("v", new ArithExp("+", new VarExp("v"), new ValueExp(new IntValue(1))))),
                                new RelationalExp("==", new VarExp("v"), new ValueExp(new IntValue(3)))),
                                new PrintStmt(new ArithExp("*", new VarExp("v"), new ValueExp(new IntValue(10)))))));
        stmts.add(ex19);

        //SLEEP STMT
        IStmt ex20 = new CompStmt(new VarDeclStmt("v", new IntType()),
                new CompStmt(new AssignStmt("v", new ValueExp(new IntValue(10))),
                        new CompStmt(new ForkStmt(new CompStmt(new AssignStmt("v", new ArithExp("-", new VarExp("v"), new ValueExp(new IntValue(1)))),
                                new CompStmt(new AssignStmt("v", new ArithExp("-", new VarExp("v"), new ValueExp(new IntValue(1)))),
                                        new PrintStmt(new VarExp("v"))))),
                                new CompStmt(new SleepStmt(10), new PrintStmt(new ArithExp("*", new VarExp("v"), new ValueExp(new IntValue(10))))))));
        stmts.add(ex20);

        //SLEEP STMT
        IStmt ex21 = new CompStmt(new VarDeclStmt("v", new IntType()),
                new CompStmt(new AssignStmt("v", new ValueExp(new IntValue(0))),
                        new CompStmt(new WhileStmt(new RelationalExp("<", new VarExp("v"), new ValueExp(new IntValue(3))),
                                new CompStmt(new ForkStmt(new CompStmt(new PrintStmt(new VarExp("v")), new AssignStmt("v", new ArithExp("+", new VarExp("v"), new ValueExp(new IntValue(1)))))), new AssignStmt("v", new ArithExp("+", new VarExp("v"), new ValueExp(new IntValue(1)))))),
                                new CompStmt(new SleepStmt(5), new PrintStmt(new ArithExp("*", new VarExp("v"), new ValueExp(new IntValue(10))))))));
        stmts.add(ex21);

        //WAIT STMT
        IStmt ex22 = new CompStmt(new VarDeclStmt("v", new IntType()),
                new CompStmt(new WaitStmt(10), new PrintStmt(new ArithExp("*", new VarExp("v"), new ValueExp(new IntValue(10))))));
        stmts.add(ex22);

        //MUL Exp
        IStmt ex23 = new CompStmt(new VarDeclStmt("v1", new IntType()),
                new CompStmt(new VarDeclStmt("v2", new IntType()),
                        new CompStmt(new AssignStmt("v1", new ValueExp(new IntValue(2))),
                                new CompStmt(new AssignStmt("v2", new ValueExp(new IntValue(3))),
                                        new IfStmt(new ValueExp(new BoolValue(true)), new PrintStmt(new MULExp(new VarExp("v1"), new VarExp("v2"))), new PrintStmt(new VarExp("v1")))))));
        stmts.add(ex23);

        //DO WHILE STMT
        IStmt ex24 = new CompStmt(new VarDeclStmt("v", new IntType()),
                new CompStmt(new AssignStmt("v", new ValueExp(new IntValue(4))),
                        new CompStmt(new DoWhileStmt(new CompStmt(new PrintStmt(new VarExp("v")), new AssignStmt("v", new ArithExp("-", new VarExp("v"), new ValueExp(new IntValue(1))))),
                                new RelationalExp(">", new VarExp("v"), new ValueExp(new IntValue(0)))),
                                new PrintStmt(new VarExp("v")))));
        stmts.add(ex24);

        //COUNT DOWN LATCH
        IStmt ex25 = new CompStmt(new VarDeclStmt("v1",new RefType(new IntType())),
                new CompStmt(new VarDeclStmt("v2", new RefType(new IntType())),
                        new CompStmt(new VarDeclStmt("v3", new RefType(new IntType())),
                                new CompStmt(new VarDeclStmt("cnt", new IntType()),
                                        new CompStmt(new aHStmt("v1", new ValueExp(new IntValue(2))),
                                                new CompStmt(new aHStmt("v2", new ValueExp(new IntValue(3))),
                                                        new CompStmt(new aHStmt("v3", new ValueExp(new IntValue(4))),
                                                                new CompStmt(new newLatchStmt("cnt", new rHExp(new VarExp("v2"))),
                                                                        new CompStmt(new ForkStmt(
                                                                                new CompStmt(new wHStmt("v1", new ArithExp("*", new rHExp(new VarExp("v1")), new ValueExp(new IntValue(10)))),
                                                                                        new CompStmt(new PrintStmt(new rHExp(new VarExp("v1"))),
                                                                                                new CompStmt(new countDownStmt("cnt"),
                                                                                                        new ForkStmt(
                                                                                                                new CompStmt(new wHStmt("v2", new ArithExp("*", new rHExp(new VarExp("v2")), new ValueExp(new IntValue(10)))),
                                                                                                                        new CompStmt(new PrintStmt(new rHExp(new VarExp("v2"))),
                                                                                                                                new CompStmt(new countDownStmt("cnt"),
                                                                                                                                        new ForkStmt(
                                                                                                                                                new CompStmt(new wHStmt("v3", new ArithExp("*", new rHExp(new VarExp("v3")), new ValueExp(new IntValue(10)))),
                                                                                                                                                        new CompStmt(new PrintStmt(new rHExp(new VarExp("v3"))), new countDownStmt("cnt")))))))))))),
                                                                                new CompStmt(new AwaitStmt("cnt"),
                                                                                        new CompStmt(new PrintStmt(new ValueExp(new IntValue(100))),
                                                                                                new CompStmt(new countDownStmt("cnt"), new PrintStmt(new ValueExp(new IntValue(100)))))))
                                                                ))))))));
        stmts.add(ex25);
    }
}

