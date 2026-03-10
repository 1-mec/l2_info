<x-app-layout>
    <x-slot name="header">
        <h2 class="font-semibold text-xl text-gray-800 leading-tight">
            {{ __('Author') }}: {{ $author->firstname }} {{ $author->name }}
        </h2>
    </x-slot>

    <div class="py-12">
        <div class="max-w-7xl mx-auto sm:px-6 lg:px-8">
            <div class="bg-white overflow-hidden shadow-sm sm:rounded-lg">
                <div class="p-6 text-gray-900">
                    <div class="rounded-xl bg-gray-800"><!-- image --></div>
                    <div>
                        <p class="font-bold text-xl">{{ $author->firstname }} {{ $author->name }}</p>
                        <p>{{ $author->biography }}</p>
                        @if ($author->books)
                        <ul>
                            @foreach($author->books as $book)
                            <li><a href='{{ route('books.show', $book->id) }}' title="{{ $book->title }}" class="underline">{{ $book->title }}</a></li>
                            @endforeach
                        </ul>
                        @endif
                    </div>
                </div>
            </div>
        </div>
    </div>
</x-app-layout>
