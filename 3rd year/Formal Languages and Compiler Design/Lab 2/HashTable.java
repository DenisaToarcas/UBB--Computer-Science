import java.util.ArrayList;

public class HashTable<K, V> {
    private final Integer size;
    private final ArrayList<ArrayList<Pair<K, V>>> table;

    public HashTable(Integer size) {
        this.size = size;
        this.table = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            this.table.add(new ArrayList<>());
        }
    }

    private Integer hash(K key) {
        int characters_sum = 0;
        char[] key_chars = key.toString().toCharArray();
        for (int i = 0; i < key_chars.length; i++) {
            characters_sum += key_chars[i];
        }
        return characters_sum % size;
    }

    // Add a key-value pair to the hash table
    public boolean add(K key, V value) {
        if (containsKey(key)) {
            return false;
        }

        Integer pos = hash(key);
        ArrayList<Pair<K, V>> bucket = this.table.get(pos);
        bucket.add(new Pair<>(key, value));
        return true;
    }

    // Check if the table contains a key
    public boolean containsKey(K key) {
        return findPositionOfKey(key) != null;
    }

    // Find the position of a key in the table
    public Pair<Integer, Integer> findPositionOfKey(K key) {
        int pos = hash(key);

        if (!table.get(pos).isEmpty()) {
            ArrayList<Pair<K, V>> bucket = this.table.get(pos);
            for (int i = 0; i < bucket.size(); i++) {
                if (bucket.get(i).getKey().equals(key)) {
                    return new Pair<>(pos, i); // Bucket and index in the bucket
                }
            }
        }

        return null;
    }

    // Retrieve value by the key's position
    public V findValueByKey(K key) {
        Pair<Integer, Integer> pos = findPositionOfKey(key);

        if (pos == null) {
            throw new IndexOutOfBoundsException("Invalid key position");
        }

        return this.table.get(pos.getKey()).get(pos.getValue()).getValue();
    }

    // Retrieve terminal at that position
    public K findByPosition(Pair<Integer, Integer> pos) {
        if (pos == null) {
            throw new IndexOutOfBoundsException("Invalid position");
        }

        if (this.table.size() < pos.getKey() || this.table.get(pos.getKey()).size() < pos.getValue()) {
            throw new IndexOutOfBoundsException("Invalid position");
        }

        return this.table.get(pos.getKey()).get(pos.getValue()).getKey();
    }

    // Display the hash table
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("HashTable { ");
        for (int i = 0; i < table.size(); i++) {
            sb.append("Bucket ").append(i).append(": ");
            if (!table.get(i).isEmpty()) {
                for (Pair<K, V> pair : table.get(i)) {
                    sb.append(pair.toString()).append(", ");
                }
            }
        }
        sb.append("}");
        return sb.toString();
    }

    public Integer getSize() {
        return size;
    }
}
