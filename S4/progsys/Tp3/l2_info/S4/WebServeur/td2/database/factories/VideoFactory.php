<?php

namespace Database\Factories;

use Illuminate\Database\Eloquent\Factories\Factory;

/**
 * @extends \Illuminate\Database\Eloquent\Factories\Factory<\App\Models\Video>
 */
class VideoFactory extends Factory
{
    public function definition(): array
    {
            return [
            'name' => fake()->Str::random(255),
            'description' => fake()->Str::rand(255),
            'image' => fake()->Str::random(255),
            'year' => fake()->rand(1990,2025),
            'price' => fake()->rand(20,80),
            'is_published' => boolval(true),
        ];
    }
}
