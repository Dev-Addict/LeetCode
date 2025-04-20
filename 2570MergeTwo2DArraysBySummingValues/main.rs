use std::collections::HashMap;

impl Solution {
    pub fn merge_arrays(nums1: Vec<Vec<i32>>, nums2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut record: HashMap<i32, i32> = HashMap::new();

        for pair in &nums1 {
            let (id, value) = (pair[0], pair[1]);

            record.insert(id, value);
        }

        for pair in &nums2 {
            let (id, value) = (pair[0], pair[1]);

            if let Some(item) = record.get_mut(&id) {
                *item += value;
            } else {
                record.insert(id, value);
            }
        }

        record
            .into_iter()
            .map(|(k, v)| vec![k, v])
            .collect()
            .sort_by_key(|pair| pair[0]);
    }
}
