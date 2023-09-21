// https://leetcode.com/problems/snapshot-array

import java.util.TreeMap;

class SnapshotArray {
    TreeMap<Integer, Integer>[] snapshotArray; // Array of TreeMaps to store snapshots for each index
    int snapId = 0; // ID to track the current snapshot

    public SnapshotArray(int length) {
        // Initialize the TreeMap array with the given length
        snapshotArray = new TreeMap[length];

        for (int i = 0; i < length; i++) {
            // Create a new TreeMap for each index
            snapshotArray[i] = new TreeMap<Integer, Integer>();
            snapshotArray[i].put(0, 0); // Initialize the initial snapshot with value 0
        }
    }

    public void set(int index, int val) {
        snapshotArray[index].put(snapId, val); // Update the value at the given index for the current snapshot
    }

    public int snap() {
        return snapId++; // Increment the snapshot ID and return the updated ID
    }

    public int get(int index, int snapId) {
        return snapshotArray[index].floorEntry(snapId).getValue(); // Get the value at the given index for the specified snapshot ID
    }
}


/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray obj = new SnapshotArray(length);
 * obj.set(index,val);
 * int param_2 = obj.snap();
 * int param_3 = obj.get(index,snap_id);
 */