public class SymbolTable {

    private Integer size;
    private HashTable<String, String> identifiersSymbolTable;
    private HashTable<String, Object> constantsSymbolTable;

    public SymbolTable(Integer size) {
        this.size = size;
        this.identifiersSymbolTable = new HashTable<>(size);
        this.constantsSymbolTable = new HashTable<>(size);
    }

    // getters and setters for size
    public Integer getSize() {
        return size;
    }

    public void setSize(Integer size) {
        this.size = size;
    }

    // getters and setters for IdentifiersST and ConstantsST
    public HashTable<String, String> getIdentifiersSymbolTable() {
        return identifiersSymbolTable;
    }

    public void setIdentifiersSymbolTable(HashTable<String, String> identifiersSymbolTable) {
        this.identifiersSymbolTable = identifiersSymbolTable;
    }

    public HashTable<String, Object> getConstantsSymbolTable() {
        return constantsSymbolTable;
    }

    public void setConstantsSymbolTable(HashTable<String, Object> constantsSymbolTable) {
        this.constantsSymbolTable = constantsSymbolTable;
    }

    // findByPosition
    public String findByPositionInIdentifiersST(Pair<Integer, Integer> position) {
        return this.identifiersSymbolTable.findByPosition(position);
    }

    public String findByPositionInConstantsST(Pair<Integer, Integer> position) {
        return this.constantsSymbolTable.findByPosition(position);
    }

    // findValueByKey
    public String findValueByKeyInIdentifiersST(String key) {
        return this.identifiersSymbolTable.findValueByKey(key);
    }

    public Object findValueByKeyInConstantsST(String key) {
        return this.constantsSymbolTable.findValueByKey(key);
    }

    // containsKey
    public boolean containsKeyInIdentifiersST(String symbol) {
        return this.identifiersSymbolTable.containsKey(symbol);
    }

    public boolean containsKeyInConstantsST(String symbol) {
        return this.constantsSymbolTable.containsKey(symbol);
    }

    // add
    public boolean addInIdentifiersST(String symbol, String value) {
        return this.identifiersSymbolTable.add(symbol, value);
    }

    public boolean addInConstantsST(String symbol, Object value) {
        return this.constantsSymbolTable.add(symbol, value);
    }

    // findPositionOfKey
    public Pair<Integer, Integer> findPositionOfKeyInIdentifiersST(String symbol) {
        return this.identifiersSymbolTable.findPositionOfKey(symbol);
    }

    public Pair<Integer, Integer> findPositionOfKeyInConstantsST(String symbol) {
        return this.constantsSymbolTable.findPositionOfKey(symbol);
    }

    @Override
    public String toString() {
        return this.identifiersSymbolTable.toString() + "\n" + this.constantsSymbolTable.toString();
    }
}
