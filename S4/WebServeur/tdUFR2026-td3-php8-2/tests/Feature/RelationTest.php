<?php

namespace Tests\Feature;

use Illuminate\Foundation\Testing\RefreshDatabase;
use Illuminate\Foundation\Testing\WithFaker;
use Tests\TestCase;
use App\Models\Author;
use App\Models\Book;

class RelationTest extends TestCase
{
    use RefreshDatabase;

    public function test_author_has_many_books(): void {
        $author = Author::factory()->create();
        $booksCount = 2;
        $books = Book::factory($booksCount)->create(['author_id' => $author->id]);

        $this->assertSame($booksCount, $author->books()->count());

    }

    public function test_book_belongs_to_author(): void {
        $author = Author::factory()->create();
        $book = Book::factory()->create(['author_id' => $author->id]);

        $this->assertSame(1, $book->author()->count());

    }
}
