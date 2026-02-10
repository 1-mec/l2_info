<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use Illuminate\View\View;
use App\Models\Author;

class AuthorController extends Controller
{
    public function index(): View {
        $authors = Author::withCount('books')->paginate();

        return view('authors.index', compact('authors'));
    }

    public function show(int $id): View {
        $author = Author::with('books')->find($id);

        return view('authors.show', compact('author'));
    }
}
