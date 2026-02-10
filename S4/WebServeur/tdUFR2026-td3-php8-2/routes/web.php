<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\VideoController;
use App\Http\Controllers\ProfileController;
use App\Http\Controllers\BookController;
use App\Http\Controllers\AuthorController;

Route::get('/', function () {
    return view('welcome');
});

Route::get('/dashboard', function () {
    return view('dashboard');
})->middleware(['auth', 'verified'])->name('dashboard');

Route::middleware('auth')->group(function () {
    Route::get('/profile', [ProfileController::class, 'edit'])->name('profile.edit');
    Route::patch('/profile', [ProfileController::class, 'update'])->name('profile.update');
    Route::delete('/profile', [ProfileController::class, 'destroy'])->name('profile.destroy');

    Route::get('/videos', [VideoController::class, 'index'])->name('videos.index');
    Route::get('/videos/{id}', [VideoController::class, 'show'])->name('videos.show');

    Route::get('/books', [BookController::class, 'index'])->name('books.index');
    Route::get('/books/{id}', [BookController::class, 'show'])->name('books.show');
    Route::get('/books', [BookController::class, 'index']);
    Route::get('/books/{id}', [BookController::class, 'show']);
    Route::get('/books/{id}/edit', [BookController::class, 'edit']);
    Route::put('/books/{id}', [BookController::class, 'udpate']);
    Route::get('/books/create', [BookController::class, 'create']);
    Route::post('/books', [BookController::class, 'store']);
    Route::delete('/books/{id}', [BookController::class, 'destroy']);
    Route::resource('/books', BookController::class);

    Route::get('/authors', [AuthorController::class, 'index'])->name('authors.index');
    Route::get('/authors/{id}', [AuthorController::class, 'show'])->name('authors.show');
});

require __DIR__.'/auth.php';
