// URL: https://exercism.org/tracks/cpp/exercises/two-bucket DATE: 2024-02-24

#include <bits/stdc++.h>
#include <stdexcept>

#include "two_bucket.h"


/**
 * Computes the greatest common divisor of two numbers.
 *
 * @param a The first number.
 * @param b The second number.
 * @return The greatest common divisor.
 */
int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

/**
 * Simulates the pouring of water between two buckets.
 *
 * @param from_capacity The capacity of the source bucket.
 * @param to_capacity The capacity of the destination bucket.
 * @param target_volume The target volume to achieve.
 * @return The result of the pouring action.
 */
two_bucket::bucket_result two_bucket::pour(int from_capacity, int to_capacity, int target_volume) {
	// 0 < bucket1 < bucket2
	// target_value < bucket2
	int from = from_capacity;
	int to = 0;

	int steps = 1;

	while (from != target_volume && to != target_volume) {
		int temp = std::min(from, to_capacity - to);

		to += temp;
		from -= temp;

		steps++;

		if (from == target_volume)
			return { steps, 1, to };
		else if (to == target_volume)
			return { steps, 2, from };

		if (from == 0) {
			from = from_capacity;
			steps++;
		}

		if (to == to_capacity) {
			to = 0;
			steps++;
		}
	}

	throw std::invalid_argument("Impossible");
}

/**
 * Measures the steps and result of the two-bucket problem.
 *
 * @param bucket1_capacity The capacity of the first bucket.
 * @param bucket2_capacity The capacity of the second bucket.
 * @param target_volume The target volume to achieve.
 * @param start_bucket The bucket to start filling.
 * @return The result of the measurement.
 */
two_bucket::measure_result two_bucket::measure(int bucket1_capacity, int bucket2_capacity,
	int target_volume, bucket_id start_bucket) {

	if (target_volume > bucket1_capacity && target_volume > bucket2_capacity)
		throw std::invalid_argument("Impossible");

	if ((target_volume % gcd(bucket1_capacity, bucket2_capacity)) != 0)
		throw std::invalid_argument("Impossible");

	if (target_volume == bucket1_capacity)
		return start_bucket == bucket_id::one ? measure_result{ 1, bucket_id::one, 0 } : measure_result{ 2, bucket_id::one, bucket2_capacity };
	else if (target_volume == bucket2_capacity)
		return start_bucket == bucket_id::two ? measure_result{ 1, bucket_id::two, 0 } : measure_result{ 2, bucket_id::two, bucket1_capacity };
	else if (start_bucket == bucket_id::one) {
		bucket_result result = pour(bucket1_capacity, bucket2_capacity, target_volume);
		bucket_id goal_bucket = result.bucket == 1 ? bucket_id::one : bucket_id::two;

		return { result.steps, goal_bucket, result.remaining_liters };
	} else {
		bucket_result result = pour(bucket2_capacity, bucket1_capacity, target_volume);
		bucket_id goal_bucket = result.bucket == 1 ? bucket_id::two : bucket_id::one;

		return { result.steps, goal_bucket, result.remaining_liters };
	}
}
