// URL: https://exercism.org/tracks/cpp/exercises/two-bucket DATE: 2024-02-24

#ifndef TWO_BUCKET_H
#define TWO_BUCKET_H


namespace two_bucket {
	enum class bucket_id {
		one,
		two
	};

	struct bucket_result {
		int steps;
		int bucket;
		int remaining_liters;
	};

	struct measure_result {
		int num_moves;
		bucket_id goal_bucket;
		int other_bucket_volume;
	};

	bucket_result pour(int from_capacity, int to_capacity, int target_volume);

	measure_result measure(
			int bucket1_capacity, int bucket2_capacity,
			int targe_volume, bucket_id start_bucket);
}

#endif
