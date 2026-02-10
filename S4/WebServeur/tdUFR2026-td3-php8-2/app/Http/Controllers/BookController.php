<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Book;
use Illuminate\View\View;

class BookController extends Controller
{
    public function index(): View {
        $books = Book::with('author')->paginate();

        return view('books.index', compact('books'));
    }

    public function show(int $id): View {
        $book = Book::with('author')->find($id);

        return view('books.show', compact('book'));
    }
    
    public function store(Request $request){
        Book::create($request->all());
        return to_route('book.index');
    }
    
    public function edit($id){
        $book = Book::find($id);
        return view('edit', compact('book'));
    }

    public function update(Request $request, $id){
        $book = Book::find($id);
        Book::update($request->all());
        return to_route('book.index');
    }

    public function destroy(book $id){
        $book = Book::find($id);
        $book->delete();
        return to_route('book.index');
    }
}
