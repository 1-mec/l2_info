<x-app-layout>
    <x-slot name="header">
        <h2 class="font-semibold text-xl text-gray-800 leading-tight">
            {{ __('Books') }}
        </h2>
    </x-slot>

    <div class="py-12">
        <div class="max-w-7xl mx-auto sm:px-6 lg:px-8">
            <div class="bg-white overflow-hidden shadow-sm sm:rounded-lg">
                <div class="p-6 text-gray-900">
                    <table class="w-full">
                        <thead>
                            <th style="text-align: left;">Id</th>
                            <th style="text-align: left;">Title</th>
                            <th style="text-align: left;">Image</th>
                            <th style="text-align: left;">Page</th>
                            <th style="text-align: left;">Price</th>
                            <th style="text-align: left;">Is published</th>
                            <th style="text-align: left;">Author</th>
                            <th style="text-align: left;">Action</th>
                        </thead>
                        <tbody>
                            @foreach($books as $book)
                                <tr>
                                    <td>{{ $book->id }}</td>
                                    <td><a href="{{ route('books.show', $book->id) }}" title="{{ $book->title }}" class="underline">{{ $book->title }}</a></td>
                                    <td>{{ $book->image }}</td>
                                    <td>{{ $book->page }}</td>
                                    <td>{{ $book->price }}€</td>
                                    <td>{{ $book->is_published ? 'Yes' : 'No'}}</td>
                                    <td><a href="{{ route('authors.show', $book->author->id) }}" title="{{ $book->author->firstname }} {{ $book->author->name }}"  class="underline">{{ $book->author->firstname }} {{ $book->author->name }}</td>
                                    <td><a href="{{ route('books.edit', $book->id )}}">Edit</a></td>
                                    <td><form method="post" action="{{ route('books.destroy', $book->id) }}">
                                            @csrf
                                            @method('delete')
                                                <div>
                                                    <a href=''>Delete</a>
                                                </div>
                                        </form>
                                    </td>
                                </tr>
                            @endforeach
                        </tbody>
                    </table>
                    {{ $books->links() }}
                </div>
            </div>
        </div>
    </div>
</x-app-layout>
