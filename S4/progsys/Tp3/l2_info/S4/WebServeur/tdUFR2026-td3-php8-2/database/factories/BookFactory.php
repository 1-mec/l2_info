<?php

namespace Database\Factories;

use Illuminate\Database\Eloquent\Factories\Factory;
use App\Models\Author;

/**
 * @extends \Illuminate\Database\Eloquent\Factories\Factory<\App\Models\Book>
 */
class BookFactory extends Factory
{
    /**
     * Define the model's default state.
     *
     * @return array<string, mixed>
     */
    public function definition(): array
    {
        $author = Author::inRandomOrder()->first();

        return [
            'title' => fake()->words(2, true),
            'description' => fake()->sentences(3, true),
            'page' => random_int(30, 200),
            'price' => random_int(15, 100),
            'is_published' => random_int(0,1),
            'author_id' => $author->id,
        ];
    }
}
