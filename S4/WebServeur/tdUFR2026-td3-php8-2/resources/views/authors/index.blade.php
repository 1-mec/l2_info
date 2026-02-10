<x-app-layout>
    <x-slot name="header">
        <h2 class="font-semibold text-xl text-gray-800 leading-tight">
            {{ __('Authors') }}
        </h2>
    </x-slot>

    <div class="py-12">
        <div class="max-w-7xl mx-auto sm:px-6 lg:px-8">
            <div class="bg-white overflow-hidden shadow-sm sm:rounded-lg">
                <div class="p-6 text-gray-900">
                    <table class="w-full">
                        <thead>
                            <th style="text-align: left;">Id</th>
                            <th style="text-align: left;">Fullname</th>
                            <th style="text-align: left;">Books</th>
                            <th style="text-align: left;">Action</th>
                        </thead>
                        <tbody>
                            @foreach($authors as $author)
                                <tr>
                                    <td>{{ $author->id }}</td>
                                    <td><a href="{{ route('authors.show', $author->id) }}" title="{{ $author->name }}" class="underline">{{ $author->firstname }} {{ $author->name }}</a></td>
                                    <td>{{ $author->books_count }}</td>
                                    <td><a href="{{ route('authors.edit', $author->id )}}">Edit</a></td>
                                    <td><form method="post" action="{{ route('authors.destroy', $author->id) }}">
                                            @csrf
                                            @method('delete')
                                                <div>
                                                    <a href=''>Delete</a>
                                                </div>
                                        </form>
                                    </td>
                                    <td></td>
                                </tr>
                            @endforeach
                        </tbody>
                    </table>
                    {{ $authors->links() }}
                </div>
            </div>
        </div>
    </div>
</x-app-layout>
