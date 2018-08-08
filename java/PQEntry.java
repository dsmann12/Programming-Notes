public class PQEntry<K extends Comparable<K>, V> implements Comparable<PQEntry<K, V>>{
	private K key;
	private V value;
	
	public PQEntry() {
		
	}

	public PQEntry(K k, V v) {
		this.key = k;
		this.value = v;
	}
	
	public void setKey(K k) {
		this.key = k;
	}

	public K getKey() {
		return this.key;
	}

	public void setValue(V v) {
		this.value = v;
	}

	public V getValue() {
		return this.value;
	}

	public String toString() {
		return this.value.toString();
	}

	public int compareTo(PQEntry<K, V> e) {
		return this.key.compareTo(e.getKey());
	}	
}
