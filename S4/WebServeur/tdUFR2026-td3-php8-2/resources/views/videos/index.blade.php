<x-app-layout>
    <x-slot name="header">
        <h2 class="font-semibold text-xl text-gray-800 leading-tight">
            {{ __('Videos') }}
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
                            <th style="text-align: left;">Year</th>
                            <th style="text-align: left;">Price</th>
                            <th style="text-align: left;">Is published</th>
                            <th style="text-align: left;">Action</th>
                        </thead>
                        <tbody>
                            @foreach($videos as $video)
                                <tr>
                                    <td>{{ $video->id }}</td>
                                    <td><a href="{{ route('videos.show', $video->id) }}" title="$video->title" class="underline">{{ $video->title }}</a></td>
                                    <td>{{ $video->image }}</td>
                                    <td>{{ $video->year }}</td>
                                    <td>{{ $video->price }}€</td>
                                    <td>{{ $video->is_published ? 'Yes' : 'No'}}</td>
                                </tr>
                            @endforeach
                        </tbody>
                    </table>
                </div>
            </div>
        </div>
    </div>
</x-app-layout>
