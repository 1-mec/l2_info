<?php

namespace App\Http\Controllers;

use App\Models\Video;
use Illuminate\View\View;


class VideoController extends Controller
{
    public function index(): View 
    {
        $videos = Video::all();

        return view('videos.index', ['videos' => $videos]);
    }

    public function show(int $id): View
    {
        $video = Video::find($id);

        return view('videos.show', ['video' => $video]);
    }
}
